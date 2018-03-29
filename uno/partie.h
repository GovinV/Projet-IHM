#ifndef GAME_H
#define GAME_H

#include <iostream>
#include<vector>
#include"pioche.h"
#include"joueur.h"

#define CARTES_MAIN 7

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
        bool plus2_actif;
        bool plus4_actif;
        int prends_toi_ca;

        unsigned int seed;

        const int nb_cartes_debut = CARTES_MAIN;


        Partie(int nbJoueur);
        Partie(int nbJoueur, unsigned int s);


        void distribution(int nb_cartes);

        void premiere_carte();

        void debut();

        void jouer();
};

#endif // GAME_H
