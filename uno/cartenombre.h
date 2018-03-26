#ifndef CARTENOMBRE_H
#define CARTENOMBRE_H

#include<iostream>
#include<string>
#include"abstractcarte.h"

//class Couleur;

class CarteNombre : public AbstractCarte
{
public:
    CarteNombre(int n, int c);
    int numero;
};

#endif // CARTENOMBRE_H
