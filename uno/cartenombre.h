#ifndef CARTENOMBRE_H
#define CARTENOMBRE_H

#include<iostream>
#include<string>
#include"carte.h"


class CarteNombre : public Carte
{
public:
    CarteNombre(int n, Couleur c);
    int numero;
};


#endif // CARTENOMBRE_H
