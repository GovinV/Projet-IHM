#ifndef PIOCHE_H
#define PIOCHE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "carte.h"
#include "cartenombre.h"
#include "changementcouleur.h"
#include "changementsens.h"
#include "plus2.h"
#include "plus4.h"
#include "tagueule.h"

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
