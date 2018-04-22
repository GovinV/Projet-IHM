#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "pioche.h"
#include "joueur.h"
#include "manche.h"
#include "types.h"

#define DEFAUT_CARTES_MAIN 7
#define LIMITE_POINTS_DEFAUT 500

/**
 * @brief Indique le statut de la partie en cours.
 *
 * PARTIE_ATTENTE_LANCEMENT : La partie est créée, mais pas lancée. Dans ce cas
 *                            ses paramètre peuvent alors être modifiés.
 *
 * PARTIE_EN_COURS : La partie est lancée et les manches se succèdent.
 *
 * PARTIE_TERMINEE : Un joueur a remplit les conditions de victoire.
 */
enum StatutPartie { PARTIE_ATTENTE_LANCEMENT=0, PARTIE_EN_COURS, PARTIE_TERMINEE };


/// TODO : Implémenter les autres types de parties.

/**
 * @brief Indique les différents types de partie
 *
 * CLASSIQUE : Une partie est constituée de plusieurs manches jusqu'à ce qu'un
 *             joueur atteigne la limite de points fixée (500 par défault).
 *
 * MANCHE_UNIQUE : Une partie n'est constituée que d'une unique manche, le
 *                 gagnant de la manche est le gagant de la partie.
 *
 * ...
 */
enum TypePartie { CLASSIQUE=0, MANCHE_UNIQUE/*, DEUX_VS_DEUX_CLASSIQUE,
                  DEUX_VS_DEUX_MANCHE_UNIQUE, ELIMINATION*/ };

/**
 * @brief La classe Partie représente une partie de Uno.
 */
class Partie
{
public:
    /**
     * @brief Constructeur de la classe Partie.
     * @param t le type de la partie (voir enum TypePartie).
     * @param nb_j le nombre de joueurs de la partie.
     * @param limite la limite de points à atteindre (dépend du type de la partie).
     */
    Partie(TypePartie t, u_int nb_j, u_int limite=LIMITE_POINTS_DEFAUT);

    /**
     * @brief Destructeur de la classe Partie.
     *
     * Supprimer l'espace alloué pour la pioche et les joueurs.
     */
    ~Partie();

    /**
     * @brief Effectue les opérations indiquant le lancement de la partie.
     */
    void start();

    /**
     * @brief Finit la partie.
     *
     * Si une manche n'est pas finie ou qu'il n'y a pas encore de gagnant dans
     * la partie, alors la partie n'est pas finie, sinon les gagnants sont
     * récupérés.
     *
     * @return vrai si la partie s'est terminée, faux si elle n'est pas finie.
     */
    bool finir_partie();

    /**
     * @brief Lance une nouvelle manche dans la partie.
     *
     * Si une manche est en cours, aucune manche n'est créée.
     *
     * Sinon, la pioche est mélangée, la manche créée, et les cartes
     * distribuées aux joueurs.
     *
     * @param joueur_debut le joueur qui débuteras la partie.
     * @return la nouvelle manche.
     */
    Manche* nouvelle_manche(u_int joueur_debut);

    /**
     * @brief Réalise les opérations permettant de finir la manche.
     *
     * Si la manche peut se terminer, alors on indique a tout les joueurs
     * qu'il faut terminer la manche, et on calcule le nombre de points gagnés
     * par le joueur gagnant la manche.
     *
     * @param force si il faut forcer la finition de la manche même si elle
     *        n'est pas terminée.
     * @return le numeros du joueur ayant remporté la manche.
     */
    int finir_manche(bool force=false);

    /**
     * @brief Distribue des cartes aux joueurs avant de commencer une manche.
     *
     * Pour distribuer, chaque joueur pioche une carte à tour de rôle.
     *
     * @param nb_cartes le nombre de cartes à distribuer.
     */
    void distribution(int nb_cartes);

    /**
     * @brief Lit le message suivant et le renvoie.
     *
     * Sert pour recevoir les informations du noyau.
     *
     * Si avant de lire un message la manche est terminée, alors on la finie
     * et si la partie n'est pas terminée on en relance une, sinon on finit
     * la partie.
     *
     * Avant de lire le message, si un joueur doit prendre une pénalité suite
     * a une omission d'annoncer 'uno', alors il pioche deux cartes.
     *
     * Si le message lu indique le debut de la partie, alors la partie est
     * lancée. De même si le message indique le début d'une manche.
     *
     * @return le message suivant dans la file de messages.
     */
    Message* update_and_get_next_message();

    /**
     * @brief Remplace un joueur de la partie par un autre.
     * @param num_j le numéros du joueurs a enlevé.
     * @param j le joueur qui remplacera un autre joueur.
     */
    void changer_joueur(u_int num_j, Joueur *j);

    /**
     * @brief Permet de récupérer le seed de la partie.
     * @return le seed de la partie.
     */
    u_int get_seed();

    /**
     * @brief Modifie le nombre de cartes a distribuer en debut de manche.
     * @param nb_cartes le nombre de cartes à distribuer au début.
     */
    void set_nb_cartes_debut(int nb_cartes);

    /**
     * @brief Permet de choisir un seed en particulier pour la partie.
     * @param s le seed choisit.
     */
    void set_seed(u_int s);

    /**
     * @brief Modifie la limite de points a atteindre pour gagner la partie.
     * @param limite la limite de points à atteindre.
     */
    void set_limite(int limite);


public:
    /// Enregistre les infos sur la partie en cours.
    InfoPartie infos;

    /// Pioche de la partie.
    Pioche* pioche;

    /// Liste des joueurs dans la partie.
    std::vector<Joueur *> joueurs;

    /// Type de la partie.
    TypePartie type;

    /// Manche en cours dans la partie.
    Manche *manche_courante;

    /// La liste des gagnants de la partie (le nombre de gagnants dépend du
    /// type de la partie).
    std::vector<int> gagnants_partie;

    /// Nombre de cartes pour commencer une manche.
    int nb_cartes_debut;

    /// Valeur paramétrant l'aléatoire du jeu.
    u_int seed;

    /// Indique si la partie a été lancée.
    StatutPartie statut_partie;

    /// Nombre de joueurs dans la partie.
    u_int nb_joueur;

    /// Limite de points a atteindre (règles selon le type de partie).
    u_int limite_points;
};

#endif // GAME_H
