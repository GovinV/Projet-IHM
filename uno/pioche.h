#ifndef PIOCHE_H
#define PIOCHE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "carte.h"

#define N_CARTES 108

class Pioche
{
public:
    /// Constructeur.
    Pioche();

    /// Mélange la pile.
    void melanger(unsigned int s);

    /// Retire la carte à la fin de la pile.
    Carte* tirer_carte();

    /// Ajoute une carte au début de la pile.
    void ajouter(Carte *c);

    /// Affiche la pile sur la sortie standard.
    void afficher();

public:
    /// Vector représentant la pile des cartes.
    std::vector<Carte*> pile;
};

#endif // PIOCHE_H
