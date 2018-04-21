#include "joueur.h"


Joueur::Joueur(u_int num, InfoPartie *i)
{
    uno = UNOSTATE_FAUX;
    points = 0;
    manche_courante = NULL;
    num_joueur = num;
    carte_piochee = NULL;

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
        //piocher(2);
        uno = UNOSTATE_PENALITE;
        return true;
    }
    else
    {
        return false;
    }
}


bool Joueur::piocher(bool possibilitee_poser)
{
    bool posable;

    // Fait piocher au joueur le nombre de Cartes necessaire.
    posable = piocher(manche_courante->prends_toi_ca, possibilitee_poser);

    if(!posable)
    {
        // Indique à la manche que le joueur courant a pioché.
        manche_courante->joueur_pioche();
    }

    return posable;
}


bool Joueur::piocher(int nb_cartes, bool possibilitee_poser)
{
    Carte *tiree;

    uno = UNOSTATE_FAUX;

    if(nb_cartes == 1)
    {
        tiree = manche_courante->pioche->tirer_carte();
        if(possibilitee_poser && manche_courante->est_jouable(tiree))
        {
            carte_piochee = tiree;
            return true;
        }
        else
        {
            cmain.push_back(tiree);
            std::cout << "Le joueur " << num_joueur
                      << " a pioché : " << cmain.back() << std::endl;
            trier_main();
            return false;
        }
    }
    else
    {
        for(int i=0; i<nb_cartes; i++)
        {
            cmain.push_back(manche_courante->pioche->tirer_carte());
            std::cout << "Le joueur " << num_joueur
                      << " a pioché : " << cmain.back() << std::endl;
        }
        trier_main();
        return false;
    }
}


void Joueur::joue_carte_piochee(bool jouer_la_carte)
{
    if(carte_piochee == NULL)
    {
        std::cerr << "Erreur : la carte piochée n'était pas jouable." << std::endl;
        return;
    }

    if(jouer_la_carte)
    {
        manche_courante->joueur_joue(carte_piochee);
        carte_piochee = NULL;
    }
    else
    {
        cmain.push_back(carte_piochee);
        manche_courante->joueur_pioche();
        carte_piochee = NULL;
        trier_main();
    }
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
        manche_courante->joueur_change_couleur(c, num_joueur);
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
        choix = l_couleurs_candidates[my_rand()%4];
    }
    else
    {
        choix = cmain[0]->couleur;
    }

    std::cout << "Le joueur " << num_joueur << " a choisit une nouvelle couleur"
              << ", le " << couleur_to_string(choix) << std::endl;

    manche_courante->joueur_change_couleur(choix, num_joueur);

    return choix;
}


std::vector<int> Joueur::recherche_cartes_jouables()
{
    std::vector<int> cartes_jouables;
    int nb_cartes = cmain.size();

    for(int i=0; i<nb_cartes; i++)
    {
        if(manche_courante->est_jouable(cmain[i]))
        {
            cartes_jouables.push_back(i);
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
        std::cout << "Le joueur " << num_joueur << " a joué : "
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
    std::cout << "joueur " << num_joueur << std::endl;
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

    std::cout << "\nCartes en main du joueur " << num_joueur
              << " :" << std::endl;

    for(int i=0; i<nb_cartes; i++)
    {
       std::cout << "Indice " << i << " : " << cmain[i] << std::endl;
    }

    std::cout << std::endl;
}


Joueur::~Joueur()
{

}


