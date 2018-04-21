#include "joueuria.h"
#include "partie.h"



JoueurIA::JoueurIA(Joueur *j, StyleIA s, Partie *p) : Joueur(j->num_joueur, j->infos)
{
    std::cout << "Le joueur " << num_joueur << " est une IA" << std::endl;

    manche_courante = j->manche_courante;
    cmain = j->cmain;
    uno = j->uno;
    points = j->points;

    partie = p;

    style = s;
}


void JoueurIA::action_par_defaut()
{
    switch (style) {
    case SIMPLET:
        action_par_defaut_simplet();
        break;

    case MOYEN:
        action_par_defaut_moyen();
        break;

    default:
        break;
    }
}

void JoueurIA::action_par_defaut_simplet()
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();

    if(cartes_jouables.empty())
    {
        piocher();
    }
    else
    {
        if(cmain.size() <= 2 && my_rand()%2==0)
        {
            appuie_uno();
        }
        jouer(cartes_jouables[0]);
    }
}

void JoueurIA::action_par_defaut_moyen()
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    int nb_jouables = cartes_jouables.size();
    std::vector<int> score_cartes(nb_jouables, 0);
    int nb_cartes_couleurs[5] = {0, 0, 0, 0, 0};
    int nb_cartes_non_noir;
    int max_score = -1, carte_a_jouer;

    int nb_cartes_suivant = partie->joueurs[(num_joueur+ manche_courante->nb_joueur
                          + manche_courante->sens) % manche_courante->nb_joueur]->cmain.size();

    for(u_int i=0; i<partie->nb_joueur; i++)
    {
        if(i != num_joueur && partie->joueurs[i]->cmain.size() == 1)
        {
            partie->joueurs[i]->appuie_contre_uno();
        }
    }

    if(cartes_jouables.empty())
    {
        piocher();
    }
    else
    {
        carte_a_jouer = cartes_jouables[0];

        if(cmain.size() <= 2)
        {
            appuie_uno();
        }

        for(int i=0; i<nb_jouables; i++)
        {
            nb_cartes_couleurs[cmain[cartes_jouables[i]]->couleur]++;
        }

        nb_cartes_non_noir = nb_jouables - nb_cartes_couleurs[NOIR];

        for(int i=0; i<nb_jouables; i++)
        {
            for(int j=i+1; j<nb_jouables; j++)
            {
                if(egalite_cartes(cmain[cartes_jouables[i]], cmain[cartes_jouables[j]]))
                {
                    score_cartes[i] += 20;
                    score_cartes[j] += 20;
                }
            }

            if(cmain[cartes_jouables[i]]->type == NUMERO)
            {
                score_cartes[i] += cmain[cartes_jouables[i]]->valeur;
            }
            else if(cmain[cartes_jouables[i]]->type == JOKER)
            {
                score_cartes[i] += 1;
            }
            else if(cmain[cartes_jouables[i]]->type != PLUS_QUATRE)
            {
                if(nb_cartes_suivant <= 2)
                {
                    score_cartes[i] += 150;
                }
                else
                {
                    score_cartes[i] += my_rand()%10;
                }
            }
            else if(nb_cartes_suivant <= 2)
            {
                score_cartes[i] += 200;
            }

            if(cmain[cartes_jouables[i]]->couleur == manche_courante->couleur_active)
            {
                score_cartes[i] += 100;
            }

            score_cartes[i] += (int)(1.0 * nb_cartes_couleurs[cmain[cartes_jouables[i]]->couleur] / nb_cartes_non_noir * 100);

            if(score_cartes[i] > max_score)
            {
                max_score = score_cartes[i];
                carte_a_jouer = cartes_jouables[i];
            }
        }
        jouer(carte_a_jouer);
        //jouer(cartes_jouables[0]);
    }
}

Couleur JoueurIA::choisir_couleur_defaut()
{
    Couleur choix;

    switch(style) {
        case SIMPLET:
            choix = choisir_couleur_simplet();
            break;

        case MOYEN:
            choix = choisir_couleur_moyen();
            break;

        default:
            break;
    }

    std::cout << "Le joueur " << num_joueur << " a choisit une nouvelle couleur"
              << ", le " << couleur_to_string(choix) << std::endl;

    manche_courante->couleur_active = choix;
    return choix;
}

Couleur JoueurIA::choisir_couleur_simplet()
{
    Couleur l_couleurs_candidates[4] = {ROUGE, VERT, BLEU, JAUNE};
    Couleur choix;

    if(cmain.empty() || cmain[0]->couleur == NOIR)
    {
        choix = l_couleurs_candidates[my_rand()%4];
    }
    else
    {
        choix = cmain[0]->couleur;
    }

    return choix;
}

Couleur JoueurIA::choisir_couleur_moyen()
{
    Couleur l_couleurs_candidates[4] = {ROUGE, VERT, BLEU, JAUNE};
    Couleur choix;
    int nb_cartes_couleurs[5] = {0, 0, 0, 0, 0};
    int nb_cartes = cmain.size();

    for(int i=0; i<nb_cartes; i++)
    {
        nb_cartes_couleurs[cmain[i]->couleur]++;
    }

    int nb_opti = 0;

    if(nb_cartes_couleurs[4]>0)
    {
        for(int i=0; i<4; i++)
        {
            if(nb_cartes_couleurs[i] > nb_opti)
            {
                nb_opti = nb_cartes_couleurs[i];
                choix = l_couleurs_candidates[i];
            }
        }
    }
    else
    {
        for(int i=0; i<4; i++)
        {
            if(nb_cartes_couleurs[i] < nb_opti)
            {
                nb_opti = nb_cartes_couleurs[i];
                choix = l_couleurs_candidates[i];
            }
        }
    }

    /*for(int i=0; i<4; i++)
    {
        if(nb_cartes_couleurs[i] > nb_opti)
        {
            nb_opti = nb_cartes_couleurs[i];
            choix = l_couleurs_candidates[i];
        }
    }*/

    if(nb_opti == 0)
    {
        return l_couleurs_candidates[my_rand()%4];
    }
    else
    {
        return choix;
    }

    /*for(int i=0; i<nb_cartes; i++)
    {
        switch (cmain[i]->type) {
        case NUMERO:

            break;
        default:
            break;
        }
    }*/
}

