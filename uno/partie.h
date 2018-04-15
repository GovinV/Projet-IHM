#ifndef GAME_H
#define GAME_H

#include <iostream>
#include<vector>
#include"pioche.h"
#include"joueur.h"
#include "manche.h"

#define DEFAUT_CARTES_MAIN 7

enum TypePartie { CLASSIQUE, MANCHE_UNIQUE, DEUX_VS_DEUX_CLASSIQUE,
                  DEUX_VS_DEUX_MANCHE_UNIQUE, ELIMINATION };


enum TypeMessage { PARTIE_DEBUT, PARTIE_FIN, MANCHE_DEBUT, MANCHE_FIN,
                   JOUEUR_ACTION, JOUEUR_CHOIX_COULEUR };


struct Message{
    TypeMessage type;
    int num_joueur;
};

struct InfoPartie{
    std::vector<Message> messages;
    int nb_messages;
    int num_next_message;
    Message *get_next_message()
    {
        if(num_next_message >= nb_messages)
        {
            return NULL;
        }
        else
        {
            return &messages[num_next_message++];
        }
    }
};

class Partie
{
public:
    /// Constructeur.
    Partie(TypePartie t, int nb_j, int limite=500);

    ~Partie();

    /// Indique si la partie est finie (en fonction du type de la partie).
    /// Renvoie la liste des gagnants (dépend du type de partie).
    bool partie_finie(std::vector<Joueur*> *gagnants);

    /// Indique si la manche en cours est finie.
    /// Renvoie la liste des gagants.
    bool manche_finie(Joueur **gagnant);

    /// Créé une nouvelle manche
    Manche* nouvelle_manche();

    /// Finit la manche courante.
    int finir_manche(bool force=false);

    /// Distribue des cartes aux joueurs avant de commencer une manche.
    void distribution(int nb_cartes);

    /// Renvoie le joueur à l'indice spécifié.
    Joueur *get_joueur(int indice);

    /// Modifie le nombre de cartes a distribuer en debut de manche.
    void set_nb_cartes_debut(int nb_cartes);

    /// Spécifie un seed particulier.
    void set_seed(int s);

    /// Renvoie le seed de la partie.
    int get_seed();

    /// Pioche de la partie.
    Pioche* pioche;
    /// Liste des joueurs dans la partie.
    std::vector<Joueur> joueurs;

private:


    /// Type de la partie.
    TypePartie type;
    /// Manche en cours dans la partie.
    Manche *manche_courante;

    /// Nombre de cartes pour commencer une manche.
    int nb_cartes_debut;
    /// Valeur paramétrant l'aléatoire du jeu.
    unsigned int seed;
    /// Indique si la partie a été lancée.
    bool partie_lancee;
    /// Nombre de joueurs dans la partie.
    int nb_joueur;
    /// Limite de points a atteindre (règles selon le type de partie).
    int limite_points;
};

#endif // GAME_H
