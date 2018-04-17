#ifndef JOUEURIA_H
#define JOUEURIA_H

#include "joueur.h"

// TODO : Rendre intelligent l'IA.

class JoueurIA : public Joueur
{
public:

    JoueurIA(Joueur j);

    void action_par_defaut();

    Couleur choisir_couleur_defaut();
};

#endif // JOUEURIA_H
