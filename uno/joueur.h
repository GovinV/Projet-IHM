#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include<vector>
#include<string>
#include"carte.h"
#include"cartenombre.h"
#include"pioche.h"
#include"partie.h"

class Partie;

class Joueur
{
public:
    std::vector<Carte> cmain;

    Joueur();

    void piocher(Pioche *pioche, int nb_cartes);

    void trier_main();

    int action(std::vector<int> cartes_jouables);

    std::vector<int> recherche_cartes_jouables(Carte active, Couleur couleur_active);

    bool jouer(Partie* p, Carte active, Couleur couleur_active, Carte* carte_jouee);

    void afficher_main();
};

#endif // JOUEUR_H
