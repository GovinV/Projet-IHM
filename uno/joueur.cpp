#include "joueur.h"

Joueur::Joueur()
{
    nbCartes = CARTES_MAIN;
    cmain = new AbstractCarte[7];

    std::cout << "Joueur cree avec " << nbCartes << " cartes dans la main\n";
}


