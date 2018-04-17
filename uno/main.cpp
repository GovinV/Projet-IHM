#include <iostream>
#include"partie.h"
#include"pioche.h"
#include"carte.h"
#include"joueur.h"
#include "joueuria.h"

int main()
{
    Partie jeu(MANCHE_UNIQUE, 2);

    Message *message;

    jeu.set_seed(42);

    jeu.start();

    message = jeu.update_and_get_next_message();

    while(message != NULL && message->type != FIN_PARTIE)
    {
        std::cout << message->type << "\t" << message->num_joueur << std::endl;

        switch(message->type) {
            case JOUEUR_ACTION:
                jeu.get_joueur(message->num_joueur)->action_par_defaut();
                break;

            case JOUEUR_CHOIX_COULEUR:
                jeu.get_joueur(message->num_joueur)->choisir_couleur_defaut();
                break;

            case DEBUT_PARTIE:
                std::cout << "\nLa partie commence !\n" << std::endl;
                break;

            case DEBUT_MANCHE:
                std::cout << "\nUne manche vient de commencer !\n" << std::endl;
                break;

            case FIN_MANCHE:
                std::cout << "\nUne manche s'est terminée !\n" << std::endl;
                std::cout << "Le gagnant de la manche est le joueur "
                          << message->num_joueur << "." << std::endl;
                std::cout << "\nPoints des joueurs dans la manche :" << std::endl;
                for(int i=0; i<jeu.nb_joueur; i++)
                {
                    std::cout << "Joueur " << i << " : " << jeu.get_joueur(i)->points
                              << "." << std::endl;
                }
                break;

            default:
                break;
        }

        message = jeu.update_and_get_next_message();
    }

    std::cout << "\nLa partie est terminée !\n" << std::endl;
    if(jeu.gagnants_partie.size()==1)
    {
        std::cout << "Le gagnant de la partie est le joueur "
                  << jeu.gagnants_partie[0] << "." << std::endl;
    }
    else
    {
        std::cout << "Les gagnants sont les joueurs ";
        for(int i=0; i<jeu.gagnants_partie.size(); i++)
        {
            std::cout << jeu.gagnants_partie[i] << " ";
        }
        std::cout << "." << std::endl;
    }
    std::cout << "\nPoints des joueurs dans la partie :" << std::endl;
    for(int i=0; i<jeu.nb_joueur; i++)
    {
        std::cout << "Joueur " << i << " : " << jeu.get_joueur(i)->points
                  << "." << std::endl;
    }

    return 0;
}

