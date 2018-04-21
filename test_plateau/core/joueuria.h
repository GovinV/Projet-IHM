#ifndef JOUEURIA_H
#define JOUEURIA_H

#include "joueur.h"

enum StyleIA { SIMPLET }; // TODO : Ajouter d'autre styles

// TODO : Rendre intelligent l'IA.

class JoueurIA : public Joueur
{
public:

    JoueurIA(Joueur j, StyleIA s);

    void action_par_defaut();

    Couleur choisir_couleur_defaut();

 public:
    StyleIA style;
};

#endif // JOUEURIA_H
