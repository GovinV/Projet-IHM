#ifndef CARTENOMBRE_H
#define CARTENOMBRE_H

#include<iostream>
#include"carte.h"


class CarteNombre : public Carte
{
public:
    CarteNombre(int n, Couleur c);
};


#endif // CARTENOMBRE_H
