#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <iostream>

typedef unsigned int u_int;

/**
 * @brief The TypeMessage enum
 */
enum TypeMessage { DEBUT_PARTIE, FIN_PARTIE, DEBUT_MANCHE, FIN_MANCHE,
                   JOUEUR_ACTION, JOUEUR_CHOIX_COULEUR };

/**
 * @brief The Message struct
 */
struct Message{
    TypeMessage type;
    u_int num_joueur;
};

/**
 * @brief The InfoPartie struct
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

std::ostream &operator << (std::ostream &out, const TypeMessage t);



#endif // TYPES_H
