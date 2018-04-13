#include <iostream>
#include"partie.h"
#include"pioche.h"
#include"carte.h"
#include"joueur.h"


int main()
{
   Partie jeu(MANCHE_UNIQUE, 2);

   std::vector<Joueur*> gagnants_partie;
   std::vector<Joueur*> gagnants_manche;
   int joueur_suivant;

   jeu.set_seed(42);

   while(!jeu.partie_finie(&gagnants_partie))
   {
       Manche *m = jeu.nouvelle_manche();

       while(!jeu.manche_finie(&gagnants_manche))
       {
            joueur_suivant = m->joueur_suivant();
            // Si joueur_suivant c'est moi, alors interaction IHM
            // Si c'est un autre joueur, attente de son action
            jeu.get_joueur(joueur_suivant).action_par_defaut();

            if(m->tours.back().carte->couleur == NOIR)
            {
                jeu.get_joueur(joueur_suivant).choisir_couleur_defaut();
            }
       }
   }

   return 0;
}

