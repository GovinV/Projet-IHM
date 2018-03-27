#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include<vector>
#include<string>
#include"carte.h"
#include"cartenombre.h"
#include"pioche.h"

#define CARTES_MAIN 7

class Joueur
{
public:
    std::vector<Carte> cmain;

    Joueur();
    Joueur(Pioche *p);

    int trouver(Carte c);
    void piocher(Pioche *pioche);
    void trierMain();
    int action(std::vector<int> cartes_jouables);
    bool jouer(Pioche *pioche, Carte active, Couleur couleur_active, Carte* carte_jouee);
    void afficherMain();

};

#endif // JOUEUR_H
