#include "joueur.h"

Joueur::Joueur(int num, InfoPartie *i)
{
    uno = UNOSTATE_FAUX;
    points = 0;
    manche_courante = NULL;
    num_joueur = num;

    infos = i;
}


int Joueur::finir_manche()
{
    Carte *c;
    int somme_cartes = 0;
    int nb_cartes_restantes = cmain.size();

    uno = UNOSTATE_FAUX;

    // Les cartes sont comptabilisée et remises dans le tas.
    for(int i=0; i<nb_cartes_restantes; i++)
    {
        c = cmain.back();
        somme_cartes += c->valeur;
        cmain.pop_back();
        manche_courante->pioche->poser(c);
    }

    manche_courante = NULL;

    return somme_cartes;
}


void Joueur::appuie_uno()
{
    if(manche_courante != NULL)
    {
        if(manche_courante->joueur_courant == num_joueur && cmain.size() == 1)
        {
            uno = UNOSTATE_VRAI;
        }
        else if(manche_courante->joueur_courant == num_joueur)
        {
            uno = UNOSTATE_EN_ATTENTE;
        }
    }
}


bool Joueur::appuie_contre_uno()
{
    // NOTE : Le test 'uno != UNOSTATE_PENALITE' est probablement inutile car si le
    // joueur a déjà pris une pénalité, il ne lui reste pas qu'une seule Carte
    // dans son jeu.
    if(cmain.size() == 1 && uno != UNOSTATE_VRAI && uno != UNOSTATE_PENALITE)
    {
        piocher(2);
        uno = UNOSTATE_PENALITE;
        return true;
    }
    else
    {
        return false;
    }
}


int Joueur::piocher()
{
    int retour;
    // Fait piocher au joueur le nombre de Cartes necessaire.
    retour = piocher(manche_courante->prends_toi_ca);
    // Indique à la manche que le joueur courant a pioché.
    manche_courante->joueur_pioche();
    return retour;
}


int Joueur::piocher(int nb_cartes)
{
    for(int i=0; i<nb_cartes; i++)
    {
        cmain.push_back(manche_courante->pioche->tirer_carte());
        std::cerr << "Le joueur " << num_joueur
                  << " a pioché : " << cmain.back() << std::endl;
    }

    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    int nb_cartes_jouables = cartes_jouables.size();
    int piochee_jouable = -1;
    int indice_piochee = cmain.size()-1;

    if(nb_cartes == 1)
    {

        for(int i=0; i<nb_cartes_jouables; i++)
        {
            if(indice_piochee == cartes_jouables[i])
            {
                piochee_jouable = indice_piochee;
                break;
            }
        }
    }


    uno = UNOSTATE_FAUX;

    trier_main();

    return piochee_jouable;
}


void Joueur::trier_main()
{
    std::sort(cmain.begin(), cmain.end(), comparaison_cartes);
}


void Joueur::choisir_couleur(Couleur c)
{
    if(c != ROUGE && c != VERT && c != JAUNE && c != BLEU)
    {
        std::cerr << "Couleur non valide. La couleur active reste le "
                  << couleur_to_string(manche_courante->couleur_active)
                  << "."
                  << std::endl;
    }
    else
    {
        manche_courante->couleur_active = c;
        std::cout << "Le joueur " << num_joueur << " a choisit une nouvelle couleur"
                  << ", le " << couleur_to_string(c) << std::endl;
    }
}


Couleur Joueur::choisir_couleur_defaut()
{
    Couleur l_couleurs_candidates[4] = {ROUGE, VERT, BLEU, JAUNE};
    Couleur choix;

    if(cmain.empty() || cmain[0]->couleur == NOIR)
    {
        choix = l_couleurs_candidates[rand()%4];
    }
    else
    {
        choix = cmain[0]->couleur;
    }

    std::cout << "Le joueur " << num_joueur << " a choisit une nouvelle couleur"
              << ", le " << couleur_to_string(choix) << std::endl;

    manche_courante->couleur_active = choix;

    return choix;
}


std::vector<int> Joueur::recherche_cartes_jouables()
{
    std::vector<int> cartes_jouables;
    int nb_cartes = cmain.size();

    // Si un '+2' est posé, il ne peux poser qu'un autre '+2'
    if(manche_courante->plus2_actif)
    {
        for(int i=0; i<nb_cartes; i++)
        {
            if(cmain[i]->type == PLUS_DEUX)
            {
                cartes_jouables.push_back(i);
            }
        }
    }
    // Si un '+4' est posé, il ne peux poser qu'un autre '+4'
    else if(manche_courante->plus4_actif)
    {
        for(int i=0; i<nb_cartes; i++)
        {
            if(cmain[i]->type == PLUS_QUATRE)
            {
                cartes_jouables.push_back(i);
            }
        }
    }
    // Sinon il peux poser toutes les Cartes de même couleur ou de même type
    // que la Carte active, ainsi que les '+4' et 'JOKER'.
    else
    {
        // TODO : Refactoriser ces conditions.
        for(int i=0; i<nb_cartes; i++)
        {
            if(cmain[i]->couleur == manche_courante->couleur_active
                    || cmain[i]->couleur == NOIR)
            {
                cartes_jouables.push_back(i);
            }
            else if(cmain[i]->couleur != NOIR && cmain[i]->type == manche_courante->active->type)
            {
                if(cmain[i]->type != NUMERO || cmain[i]->valeur == manche_courante->active->valeur)
                {
                    cartes_jouables.push_back(i);
                }
            }
        }
    }

    return cartes_jouables;
}


bool Joueur::jouer(int indice_carte)
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    bool indice_valide = false;
    int nb_cartes_jouables = cartes_jouables.size();

    Carte * carte_jouee;

    for(int i=0; i<nb_cartes_jouables; i++)
    {
        if(cartes_jouables[i] == indice_carte)
        {
            indice_valide = true;
            break;
        }
    }

    // Si la Carte est jouable, elle est supprimée de sa main, on verifie si il
    // lui reste encore des cartes, si il a dit 'uno' et qu'il pose son
    // avant-dernière Carte, puis la manche est informée de la carte qu'à joué
    // le joueur.
    if(indice_valide)
    {
        std::cerr << "Le joueur " << num_joueur << " a joué : "
                  << cmain[indice_carte] << std::endl;
        carte_jouee = cmain[indice_carte];
        cmain.erase(cmain.begin()+indice_carte);

        if(cmain.size()==1 && uno == UNOSTATE_EN_ATTENTE)
        {
            uno = UNOSTATE_VRAI;
        }

        if(cmain.size() == 0)
        {
            manche_courante->joueur_gagnant = num_joueur;
            manche_courante->statut_manche = MANCHE_TERMINEE;
            infos->add_message({FIN_MANCHE, num_joueur});
        }

        manche_courante->joueur_joue(carte_jouee);
    }

    return indice_valide;
}


void Joueur::action_par_defaut()
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    if(cartes_jouables.empty())
    {
        piocher();
    }
    else
    {
        jouer(cartes_jouables[0]);
    }
}


void Joueur::afficher_main()
{
    int nb_cartes = cmain.size();

    std::cout << "Cartes en main du joueur " << num_joueur
              << " :" << std::endl;

    for(int i=0; i<nb_cartes; i++)
    {
       std::cout << cmain[i] << std::endl;
    }

    std::cout << std::endl;
}
