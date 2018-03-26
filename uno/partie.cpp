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
    for(int i=0;i<joueurs.size();i++)
    {
        joueurs[i].afficherMain();
    }


}
