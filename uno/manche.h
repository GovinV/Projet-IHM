#ifndef MANCHE_H
#define MANCHE_H

#include "carte.h"
#include "pioche.h"
#include "types.h"

enum StatutManche { MANCHE_EN_COURS, MANCHE_TERMINEE };

enum TypeActionJoueur { POSE_CARTE, PIOCHE, CHOISIT_COULEUR };

struct ActionJoueur{
    TypeActionJoueur action;
    u_int num_joueur;
    union {
        struct {
            int num_carte;
            Carte *carte_posee;
        };

        struct {
            Carte *carte_piochee;
        };

        struct {
            Couleur couleur;
        };
    };
};

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
    Manche(InfoPartie *i, Pioche *p, int nb_j, u_int joueur_debut);

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
     * @brief joueur_change_couleur
     * @param couleur
     */
    void joueur_change_couleur(Couleur couleur, u_int num_joueur);

    /**
     * @brief Renvoie le numéro du joueur suivant.
     * @return le numéro du joueur suivant.
     */
    int joueur_suivant();

    /**
     * @brief Indique si la carte spécifiée est posable sur le tas.
     * @param c la Carte à tester.
     * @return vrai si la Carte est posable, faux sinon.
     */
    bool est_jouable(Carte *c);

    void add_action_pioche(u_int num_j, Carte *c);

    void add_action_pose(u_int num_j, int num_c, Carte *c);

public:
    /// Pioche pour la manche.
    Pioche *pioche;
    /// Carte courante sur laquelle jouer.
    Carte *active;
    /// Indique la couleur a jouer.
    Couleur couleur_active;

    StatutManche statut_manche;

    InfoPartie *infos;

    std::vector<ActionJoueur> historique;

    /// Identifiant du joueur dont c'est le tour de jouer.
    u_int joueur_courant;
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
