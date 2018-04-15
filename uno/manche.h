#ifndef MANCHE_H
#define MANCHE_H

#include "carte.h"
#include "pioche.h"

class Manche
{
public:
    /**
     * @brief Manche
     * @param p
     * @param nb_j
     */
    Manche(Pioche *p, int nb_j);

    void joueur_pioche();

    void joueur_joue(Carte *c);

    int joueur_suivant();

public:
    /// Pioche pour la manche.
    Pioche *pioche;
    /// Carte courante sur laquelle jouer.
    Carte *active;
    /// Indique la couleur a jouer.
    Couleur couleur_active;
    /// Identifiant du joueur dont c'est le tour de jouer.
    int joueur_courant;
    /// Permet de gérer si le/les '+2' sur le tas ont déjà été pris en compte.
    bool plus2_actif;
    /// Permet de gérer si le/les '+4' sur le tas ont déjà été pris en compte.
    bool plus4_actif;
    /// Nombres de cartes que doit piocher le joueur dans le cas où il pioche.
    int prends_toi_ca;
    /// Nombre de joueurs dans la partie.
    int nb_joueur;
    /// Sens de la partie (1 -> horaire, 0 -> anti-horaire)
    int sens;
    /// Indice du Joueur ayant remporté la manche;
    int joueur_gagnant;
};

#endif // MANCHE_H
