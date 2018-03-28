#ifndef GAME_H
#define GAME_H

#include <iostream>
#include<vector>
#include"pioche.h"
#include"joueur.h"

class Joueur;

class Partie
{
    public:
        Pioche* pioche;
        int nb_joueur;
        std::vector<Joueur> joueurs;
        int joueur_courant;
        Carte active;
        bool partie_en_cours;


        Partie(int nbJoueur);

        void PremiereCarte();
        void debut();
        void jouer();
};

#endif // GAME_H
