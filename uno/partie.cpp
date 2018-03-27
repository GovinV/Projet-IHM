#include "partie.h"

Partie::Partie(int nbJoueur)
{
    pioche= new Pioche();
    pioche->melanger();
    pioche->afficher();

   for(int i=0;i<nbJoueur;i++)
   {
       joueurs.push_back(Joueur(pioche));
   }
}


void Partie::debut()
{
    for(unsigned int i=0;i<joueurs.size();i++)
    {
        joueurs[i].afficherMain();
    }

    pioche->PremiereCarte();

    std::cout << "Carte active : " << pioche->active << std::endl;

    joueurs[0].jouer(pioche);
}
