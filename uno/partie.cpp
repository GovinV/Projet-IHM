#include "partie.h"

Partie::Partie(int nbJoueur)
{
    nb_joueur = nbJoueur;
    pioche= new Pioche();

   for(int i=0;i<nbJoueur;i++)
   {
       joueurs.push_back(Joueur());
   }

   joueur_courant = 0;
   partie_en_cours = true;
}

void Partie::PremiereCarte()
{
    active=pioche->tirerCarte();
    while(active.numero==14)
    {
        pioche->ajouter(active);
        active=pioche->tirerCarte();
    }
}

void Partie::debut()
{
    pioche->melanger();

    //chaque joueur commence par piocher
    for(int i=0;i<CARTES_MAIN;i++)
    {
        for(unsigned int j=0;j<joueurs.size();j++)
        {
            joueurs[j].piocher(pioche);
        }
    }

    for(unsigned int i=0;i<joueurs.size();i++)
    {
        joueurs[i].afficherMain();

        joueurs[i].trierMain();

        joueurs[i].afficherMain();
    }



    PremiereCarte();

    std::cout << "Carte active : " << active << std::endl;
}

void Partie::jouer()
{
    int sens = 1;
    Carte carte_jouee;
    Couleur couleur_active = active.couleur;

    std::cout << "Debut partie\n";

    while(partie_en_cours)
    {
        std::cout << "Carte active : " << active << "\nAu tour du joueur " << joueur_courant  << std::endl;

        joueurs[joueur_courant].jouer(pioche, active, couleur_active, &carte_jouee);
        pioche->ajouter(active);
        active = carte_jouee;

        joueur_courant = (joueur_courant+sens)%nb_joueur;
    }
}
