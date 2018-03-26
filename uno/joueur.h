#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include"abstractcarte.h"
#include"cartenombre.h"
#include<vector>

#define CARTES_MAIN 7

//class AbstractCarte;

class Joueur
{
public:
    Joueur();
    //int nbCartes;
    std::vector<AbstractCarte> cmain;
};

#endif // JOUEUR_H
