#ifndef MANCHE_H
#define MANCHE_H

#include "carte.h"
#include "pioche.h"
#include "types.h"

enum StatutManche { MANCHE_EN_COURS, MANCHE_TERMINEE };

class Partie;

class Manche
{
public:
    /**
     * @brief Constructeur de la classe Manche.
     *
     * Initialise toutes les valeurs propre à la manche. Choisit aléatoirement
     * le joueur commençant la manche et tire la première Carte en évitant que
     * ce soit un '+4'.
     *
     * @param p la pioche qui sera associée à la manche.
     * @param nb_j le nombre de joueur dans la manche.
     */
    Manche(InfoPartie *i, Pioche *p, int nb_j);

    /**
     * @brief Prend en compte le fait que le joueur courant a pioché.
     *
     * Si il pioche, c'est soit qu'il ne pouvait rien jouer (il pioche une Carte)
     * ou alors qu'il subit des '+2' ou '+4' auquel cas il faut prendre en compte
     * que les Cartes ont été piochées.
     */
    void joueur_pioche();

    /**
     * @brief Prend en compte le fait que le joueur joue une Carte.
     *
     * La carte active est placée sur le tas, et la carte jouée devient la
     * nouvelle Carte active.
     * Si la carte a un effet, il est pris en compte dans la manche.
     *
     * @param c la Carte jouée.
     */
    void joueur_joue(Carte *c);

    /**
     * @brief Renvoie le numéro du joueur suivant.
     * @return le numéro du joueur suivant.
     */
    int joueur_suivant();

public:
    /// Pioche pour la manche.
    Pioche *pioche;
    /// Carte courante sur laquelle jouer.
    Carte *active;
    /// Indique la couleur a jouer.
    Couleur couleur_active;

    StatutManche statut_manche;

    InfoPartie *infos;


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
