#ifndef MANCHE_H
#define MANCHE_H

#include "carte.h"
#include "pioche.h"

/**
 * @brief The ActionJoueur enum
 */
enum ActionJoueur { PIOCHE, JOUE_CARTE };

typedef struct {
    int num_joueur;
    ActionJoueur action;
    int indice_carte;
    Carte *carte;
} tour_joueur;

class Manche
{
public:
    Manche(Pioche *p, int nb_j);

    void joueur_pioche();

    void joueur_joue(Carte *c);

    int gagnant();

    int joueur_suivant();

public:
    /// Pioche pour la manche.
    Pioche *pioche;
    /// Carte courante sur le tas du paquet.
    Carte *active;
    /// Identifiant du joueur dont c'est le tour de jouer.
    int joueur_courant;
    /// Permet de gérer si le/les '+2'/'+4' sur le tas on déjà réalisé leurs actions ou non.
    bool plus2_actif;
    bool plus4_actif;
    /// Nombres de cartes que doit piocher le joueur dans le cas où il pioche.
    int prends_toi_ca;
    /// Nombre de joueurs dans la partie.
    int nb_joueur;
    /// Sens de la partie (1 -> horaire, 0 -> anti-horaire)
    int sens;
    /// Indique la couleur a jouer.
    Couleur couleur_active;
    /// Enregistre tout les tours des joueurs.
    std::vector<tour_joueur> tours;
};

#endif // MANCHE_H
