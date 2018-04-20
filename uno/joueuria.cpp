#include "joueuria.h"
#include "partie.h"


JoueurIA::JoueurIA(Joueur *j, StyleIA s, Partie *p) : Joueur(j->num_joueur, j->infos)
{
    //std::cerr << "Le joueur " << num_joueur << " est une IA" << std::endl;

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
        /*if(cmain.size() <= 2 && rand()%2==0)
        {
            appuie_uno();
        }*/
        jouer(cartes_jouables[0]);
    }
}

void JoueurIA::action_par_defaut_moyen()
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();

    for(int i=0; i<partie->joueurs.size(); i++)
    {
        if(i != num_joueur && partie->joueurs[i]->cmain.size() == 1)
        {
            partie->joueurs[i]->appuie_contre_uno();
        }
    }

    /*std::cout << "Joueur 0 : " << partie->joueurs[0]->cmain.size() << " cartes, "
              << "Joueur 1 : " << partie->joueurs[1]->cmain.size() << " cartes, "
              << "Joueur 2 : " << partie->joueurs[2]->cmain.size() << " cartes, "
              << "Joueur 3 : " << partie->joueurs[3]->cmain.size() << " cartes.\n";*/

    if(cartes_jouables.empty())
    {
        piocher();
    }
    else
    {
        if(cmain.size() <= 2)
        {
            appuie_uno();
        }
        jouer(cartes_jouables[0]);
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
    int score_couleurs[4] = {0, 0, 0, 0};
    int nb_cartes = cmain.size();

    for(int i=0; i<nb_cartes; i++)
    {
        nb_cartes_couleurs[cmain[i]->couleur]++;
    }

    int nb_max = 0;

    for(int i=0; i<4; i++)
    {
        if(nb_cartes_couleurs[i] > nb_max)
        {
            nb_max = nb_cartes_couleurs[i];
            choix = l_couleurs_candidates[i];
        }
    }

    if(nb_max == 0)
    {
        return l_couleurs_candidates[rand()%4];
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
