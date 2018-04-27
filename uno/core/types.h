#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <iostream>
#include <stdint.h>


/**
 * @brief Redefinition de 'unsigned int' en 'u_int' pour simplifier l'écriture.
 */
typedef unsigned int u_int;

/**
 * @brief Definit les different types de messages que le noyau peut générer.
 *
 * DEBUT_PARTIE :   Indique que la partie vient de se lancer (et non pas qu'elle
 *                  vient d'être créée).
 *
 * FIN_PARTIE   :   Indique que la partie est terminée, et qu'il y a donc un
 *                  (ou plusieurs) joueur qui respecte les règles de victoire de
 *                  la partie.
 *
 * DEBUT_MANCHE :   Indique qu'une manche vient de se lancer
 *                  (équivaut à sa création).
 *
 * FIN_MANCHE   :   Indique que la manche jouée est terminée, et qu'il y a donc
 *                  un joueur ayant posé sa dernière carte.
 *
 * JOUEUR_ACTION :  Indique que la manche est en attente de l'action d'un joueur.
 *                  (Poser ou tirer une carte)
 *
 * JOUEUR_CHOIX_COULEUR : Indique qu'un joueur doit annoncer une nouvelle couleur
 *                        pour le jeu (arrive après avoir posé une carte changement
 *                        de couleur de type 'PLUS_QUATRE' ou 'JOKER').
 */
enum TypeMessage { DEBUT_PARTIE=0, FIN_PARTIE, DEBUT_MANCHE, FIN_MANCHE,
                   JOUEUR_ACTION, JOUEUR_CHOIX_COULEUR };

/**
 * @brief Structure définissant le type Message que le noyau peut générer.
 *
 * @property type le type du message (voir enum TypeMessage).
 * @property num_joueur une information en fonction du type du message :
 *           - si type == JOUEUR_ACTION ou type == JOUEUR_CHOIX_COULEUR, alors
 *             num_joueur indique le numeros du joueur concerné.
 *           - si type == DEBUT_PARTIE alors num_joueur indique le nombre de
 *             joueurs dans la partie.
 *           - si type == DEBUT_MANCHE alors num_joueur indique le numeros du
 *             joueur qui joueras en premier.
 *           - si type == FIN_PARTIE alors num_joueur indique le nombre de
 *             joueurs dans la partie.
 *           - si type == FIN_MANCHE alors num_joueur indique le numeros du
 *             gagnant de la manche.
 */
struct Message{
    TypeMessage type;
    u_int num_joueur;
};

/**
 * @brief Structure définissant le type InfoPartie.
 *
 * Cette structure contient la file des messages générés par le noyau, le nombre
 * total de messages dans la file, et le prochain a lire.
 *
 * @property messages file de Message (voir struct Message).
 * @property nb_messages nombre de messages dans la file.
 * @property num_next_message numeros du prochain message à lire.
 * @method add_message fonction d'ajout d'un Message m dans la file.
 */
struct InfoPartie{
    std::vector<Message> messages;
    int nb_messages;
    int num_next_message;
    void add_message(Message m)
    {
        messages.push_back(m);
        nb_messages++;
    }
};

/**
 * @brief Redéfinition de l'opérateur << pour l'affichage des TypeMessage.
 */
std::ostream &operator << (std::ostream &out, const TypeMessage t);

/**
 * @brief Renvoie un nombre pseudo-aléatoire.
 *
 * Définition explicite d'un générateur de nombre pseudo-aléatoires pour rendre
 * cette génération indépendante de la machine qui utilise le programme.
 *
 * @return un nombre pseudo-aléatoire.
 */
int my_rand(void);

/**
 * @brief Initialise le paramètre influant la génération de nombres pseudo-aléatoires.
 *
 * Modifie la variable utilisée dans my_rand() pour la génération de nombres
 * pseudo-aléatoires.
 *
 * @param seed la valeur qui initialise la génération des nombres.
 */
void my_srand(unsigned int seed);



#endif // TYPES_H
