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

   active = pioche->tirerCarte();
}


void Partie::debut()
{
    for(unsigned int i=0;i<joueurs.size();i++)
    {
        joueurs[i].afficherMain();
    }

    std::cout << "Carte active :" << active << std::endl;


}
