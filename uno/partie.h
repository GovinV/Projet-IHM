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


    enum StatutPartie { PARTIE_ATTENTE_LANCEMENT, PARTIE_EN_COURS, PARTIE_TERMINEE };

    /**
     * @brief The TypePartie enum
     */
    enum TypePartie { CLASSIQUE, MANCHE_UNIQUE, DEUX_VS_DEUX_CLASSIQUE,
                      DEUX_VS_DEUX_MANCHE_UNIQUE, ELIMINATION };


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
         * Supprimer l'espace alloué pour la pioche.
         */
        ~Partie();

        /**
         * @brief Effectue les opérations indiquant le lancement de la partie.
         */
        void start();

        /**
         * @brief partie_finie
         * @return
         */
        bool finir_partie();

        /// Indique si la manche en cours est finie.
        /// Renvoie la liste des gagants.
        bool manche_finie();

        /// Créé une nouvelle manche
        Manche* nouvelle_manche(u_int joueur_debut);

        /// Finit la manche courante.
        int finir_manche(bool force=false);

        /// Distribue des cartes aux joueurs avant de commencer une manche.
        void distribution(int nb_cartes);

        Message* update_and_get_next_message();

        void changer_joueur(u_int num_j, Joueur *j);

        /// Renvoie le seed de la partie.
        int get_seed();

        /// Modifie le nombre de cartes a distribuer en debut de manche.
        void set_nb_cartes_debut(int nb_cartes);

        /// Spécifie un seed particulier.
        void set_seed(int s);

        /**
         * @brief set_limite
         * @param limite
         */
        void set_limite(int limite);

        /// Pioche de la partie.
        Pioche* pioche;
        /// Liste des joueurs dans la partie.
        std::vector<Joueur *> joueurs;

    public:
        /// Enregistre les infos sur la partie en cours.
        InfoPartie infos;

        /// Type de la partie.
        TypePartie type;
        /// Manche en cours dans la partie.
        Manche *manche_courante;

        std::vector<int> gagnants_partie;

        /// Nombre de cartes pour commencer une manche.
        int nb_cartes_debut;
        /// Valeur paramétrant l'aléatoire du jeu.
        unsigned int seed;
        /// Indique si la partie a été lancée.
        StatutPartie statut_partie;
        /// Nombre de joueurs dans la partie.
        u_int nb_joueur;
        /// Limite de points a atteindre (règles selon le type de partie).
        u_int limite_points;
    };

#endif // GAME_H
