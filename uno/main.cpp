#include <iostream>
#include"partie.h"
#include"pioche.h"
#include"carte.h"
#include"joueur.h"


int main()
{
   Partie jeu(MANCHE_UNIQUE, 4);

   std::vector<Joueur*> gagnants_partie;
   Joueur *gagnant_manche;
   int joueur_suivant;

   jeu.set_seed(42);

   std::cout << "nb cartes : " << jeu.pioche->pile.size() << std::endl;

   while(!jeu.partie_finie(&gagnants_partie))
   {
       Manche *m = jeu.nouvelle_manche();

       while(!jeu.manche_finie(&gagnant_manche))
       {
            //jeu.get_joueur(0)->afficher_main();
            //jeu.get_joueur(1)->afficher_main();
            std::cerr << "Carte active : " << m->active
                      << std::endl;

            joueur_suivant = m->joueur_suivant();

            // Si joueur_suivant c'est moi, alors interaction IHM
            // Si c'est un autre joueur, attente de son action
            jeu.get_joueur(joueur_suivant)->action_par_defaut();

            if(m->couleur_active == NOIR)
            {
                jeu.get_joueur(joueur_suivant)->choisir_couleur_defaut();
            }

            std::cerr << std::endl;



            /*if(m->tours.back().action == JOUE_CARTE
                    && m->tours.back().carte->couleur == NOIR)
            {
                jeu.get_joueur(joueur_suivant).choisir_couleur_defaut();
            }*/
       }
       std::cout << "gagnant manche : " << gagnant_manche->num_joueur << std::endl;
   }
std::cout << "nb cartes : " << jeu.pioche->pile.size() << std::endl;
   std::cout << jeu.get_joueur(0)->points << "\t" << jeu.get_joueur(1)->points << "\t"
             << jeu.get_joueur(2)->points << "\t" << jeu.get_joueur(3)->points << "\t" << std::endl;

   std::cout << "Gagnant manche : " << gagnant_manche->num_joueur << std::endl;
   std::cout << "Gagnant partie : " << gagnants_partie[0]->num_joueur << std::endl;

   return 0;
}

