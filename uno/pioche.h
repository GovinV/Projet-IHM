#ifndef PIOCHE_H
#define PIOCHE_H

#include <iostream>
#include"abstractcarte.h"
//#include"cartenombre.h"

#define N_CARTES 108

class Pioche
{
    public:
        Pioche();
        int nbCartes;
        AbstractCarte pile;
};

#endif // PIOCHE_H
