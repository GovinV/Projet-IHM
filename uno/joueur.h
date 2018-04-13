#ifndef JOUEUR_H
#define JOUEUR_H

#include<iostream>
#include<vector>
#include<string>
#include"carte.h"
#include"pioche.h"
#include"partie.h"
#include "manche.h"

/**
 * @brief Permet de spécifier si le joueur a dit 'uno' au bon moment et si c'est pris en compte
 *
 * UNOSTATE_FAUX : 'uno' n'est pas prononcé (ou ne peut pas être prononcé).
 * UNOSTATE_EN_ATTENTE : 'uno' a été prononcé dans un cas probable, mais le joueur n'as
 *                       pas encore joué son avant-dernière carte.
 * UNOSTATE_VRAI : 'uno' a été prononcé a temps, et le joueurs n'as plus qu'une carte.
 * UNOSTATE_PENALITE : 'uno' n'as pas été prononcé et le joueur a été pénalisé.
 */
enum UnoState { UNOSTATE_FAUX, UNOSTATE_EN_ATTENTE, UNOSTATE_VRAI, UNOSTATE_PENALITE };



class Joueur
{
public:
    /// Constructeur.
    Joueur(int num);

    /// Finit la manche courante en comptant les points de sa main et en
    /// remettant dans la pioche les cartes restantes.
    int finir_manche();

    /// Indique que le joueur annonce 'uno', le uno n'est cependant pas validé
    /// tout de suite.
    void appuie_uno();

    /// Indique qu'un joueur adverse a annoncé un 'contre-uno'.
    /// Si le joueur adverse avait raison, il pioche deux cartes
    bool appuie_contre_uno();

    /// Le joueur pioche (par défaut ou non) le nombre de carte indiqué
    /// dans la manche courante (comprenant les éventuels malus).
    void piocher();

    /// Le joueur pioche un nombre nb_cartes de cartes dans la pioche.
    void piocher(int nb_cartes);

    /// Trie les cartes du joueur en fonction de sa couleur et de son type.
    void trier_main();

    /// Indique si le joueur a gagné la manche (si il n'a plus de cartes).
    bool gagne();

    /// Modifie la couleur active (après un '+4' ou un joker).
    void choisir_couleur(Couleur c);

    /// Choisit arbitrairement une couleur en tant que nouvelle couleur pour
    /// le jeu et la renvoie.
    Couleur choisir_couleur_defaut();

    /// Renvoie les indices des cartes jouables dans la main du joueur.
    std::vector<int> recherche_cartes_jouables();

    /// Le joueur joue la carte à la position indice_carte dans son jeu.
    bool jouer(int indice_carte);

    /// L'action du joueur se fait arbitrairement.
    /// L'action effectuee peut être récupérée dans l'historique des actions des
    /// joueurs dans la manche courante.
    void action_par_defaut();

    /// Affiche sur la sortie d'erreur les cartes dans la main du joueur.
    void afficher_main();

public:
    /// Manche en cours pendant une partie.
    Manche* manche_courante;
    /// Les cartes qu'a en main le joueur.
    std::vector<Carte*> cmain;
    /// Indique s'il a dit uno (en ayant 1 seule carte).
    UnoState uno;
    /// Nombre de points du joueur dans la partie.
    int points;
    /// Place du joueur dans le jeu (son indice).
    int num_joueur;
};

#endif // JOUEUR_H
