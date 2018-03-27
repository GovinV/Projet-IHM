#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include<vector>
#include"carte.h"
#include"cartenombre.h"
#include"pioche.h"

#define CARTES_MAIN 7

class Joueur
{
public:
    Joueur();
    Joueur(Pioche *p);

    std::vector<Carte> cmain;
    void piocher(Pioche *pioche);
    void afficherMain();
};

#endif // JOUEUR_H
