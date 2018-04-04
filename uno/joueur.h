#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include<vector>
#include<string>
#include"carte.h"
#include"pioche.h"
#include"partie.h"

class Partie;

class Joueur
{
public:
    std::vector<Carte> cmain;
    int n_joueur;
    std::string nom;
    bool uno;
    int points;

    Joueur(int n);

    void appuie_uno();
    void piocher(Pioche *pioche, int nb_cartes);
    void trier_main();
    bool gagne();
    bool decide_piocher();
    int action(std::vector<int> cartes_jouables);
    Couleur choisir_couleur();
    std::vector<int> recherche_cartes_jouables(Partie *p, Couleur couleur_active);
    bool jouer(Partie* p, Couleur couleur_active, Carte* carte_jouee);
    void afficher_main();
};

#endif // JOUEUR_H
