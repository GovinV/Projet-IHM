#include "partie.h"

Partie::Partie(int nbJoueur)
{
        std::cout << "Il y a " << nbJoueur << "joueurs.\n";

        Joueur j1;
        Joueur j2;

        Pioche pioche;

        pioche.afficher();
        pioche.melanger();
        pioche.afficher();


}
