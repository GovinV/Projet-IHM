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
        std::vector<Carte> pile;

        Pioche();

        void premiere_carte();

        void melanger();

        void afficher();

        Carte tirer_carte();

        void ajouter(Carte c);
};

#endif // PIOCHE_H
