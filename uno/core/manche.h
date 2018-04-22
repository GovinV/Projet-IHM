#ifndef MANCHE_H
#define MANCHE_H

#include "carte.h"
#include "pioche.h"
#include "types.h"

/**
 * @brief Permet d'indiquer le statut de la manche.
 */
enum StatutManche { MANCHE_EN_COURS=0, MANCHE_TERMINEE };

/**
 * @brief Permet d'indiquer l'action d'un joueur.
 */
enum TypeActionJoueur { POSE_CARTE=0, PIOCHE, CHOISIT_COULEUR };

/**
 * @brief Permet de sauvegarder toutes les actions qui se passent.
 *
 * @property action le type d'action effectuee par un joueur.
 * @property num_joueur le numero du joueur ayant effectué l'action.
 *
 * Si action == POSE_CARTE :
 *
 *  @property num_carte l'indice de la carte dans le jeu du joueur l'ayant jouée.
 *  @property carte_posee la carte que le joueur a posé.
 *
 * Si action == PIOCHE :
 *
 *  @property carte_piochee la carte piochée.
 *
 * Si action == CHOISIT_COULEUR
 *
 *  @property couleur la nouvelle couleur choisie.
 */
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

/**
 * @brief La classe manche représente une manche au cours d'une partie de uno.
 */
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
     * @param i les informations de la partie (stocke les actions réalisées).
     * @param p la pioche qui sera associée à la manche.
     * @param nb_j le nombre de joueur dans la manche.
     * @param joueur_debut le joueur qui commence la manche.
     */
    Manche(InfoPartie *i, Pioche *p, int nb_j, u_int joueur_debut);

    /**
     * @brief Prend en compte le fait que le joueur courant a pioché.
     *
     * Si il pioche, c'est soit qu'il ne pouvait rien jouer (il pioche une Carte)
     * ou alors qu'il subit des '+2' ou '+4' auquel cas il faut prendre en compte
     * que la pénalité a été prise en compte.
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
     * @brief Prend en compte le fait que le joueur change la couleur du jeu.
     * @param couleur la nouvelle couleur du jeu.
     * @param num_joueur le joueur qui a changé la couleur du jeu.
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

    /**
     * @brief Ajoute dans l'historique le fait qu'un joueur ai pioché.
     * @param num_j le numeros du joueur ayant pioché.
     * @param c la carte piochée.
     */
    void add_action_pioche(u_int num_j, Carte *c);

    /**
     * @brief Ajoute dans l'historique le fait qu'un joueur ai posé une carte.
     * @param num_j le numeros du joueur ayant posé la carte.
     * @param num_c l'indice de la carte jouée dans la main du joueur.
     * @param c la carte jouée.
     */
    void add_action_pose(u_int num_j, int num_c, Carte *c);

public:
    /// Pioche pour la manche.
    Pioche *pioche;

    /// Carte courante sur laquelle jouer.
    Carte *active;

    /// Indique la couleur à jouer.
    Couleur couleur_active;

    /// Indique le statut de la manche.
    StatutManche statut_manche;

    /// Informations de la parties (voir struct InfoPartie).
    InfoPartie *infos;

    /// Historique des action réalisées.
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
