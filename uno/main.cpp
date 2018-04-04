#include <iostream>
#include"partie.h"
#include"pioche.h"
#include"carte.h"
#include"joueur.h"


int main()
{
   Partie jeu(2);

   jeu.debut();

   jeu.jouer();

   return 0;
}

