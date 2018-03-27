#ifndef CHANGEMENTCOULEUR_H
#define CHANGEMENTCOULEUR_H

#include<iostream>
#include"carte.h"

class ChangementCouleur : public Carte
{
public:
    ChangementCouleur(Couleur c = NOIR);
};

#endif // CHANGEMENTCOULEUR_H
