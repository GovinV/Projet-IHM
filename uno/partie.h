#ifndef GAME_H
#define GAME_H

#include <iostream>
#include<vector>
#include"pioche.h"
#include"joueur.h"

class Partie
{
    public:
        Pioche* pioche;
        std::vector<Joueur> joueurs;

        Partie(int nbJoueur);

        void debut();
};

#endif // GAME_H
