#ifndef JOUEURIA_H
#define JOUEURIA_H

#include "joueur.h"
#include "partie.h"
#include "types.h"



    enum StyleIA { SIMPLET, MOYEN };

    class JoueurIA : public Joueur
    {
    public:

        JoueurIA(Joueur *j, StyleIA s, Partie *p);

        void action_par_defaut();

        void action_par_defaut_simplet();

        void action_par_defaut_moyen();

        Couleur choisir_couleur_defaut();

        Couleur choisir_couleur_simplet();

        Couleur choisir_couleur_moyen();

     public:
        StyleIA style;
        Partie *partie;
    };

#endif // JOUEURIA_H
