#include <iostream>
#include "partie.h"
#include "joueuria.h"

int simu_partie(unsigned int seed)
{
    // Déclaration des variables necessaires.
    Message *message;
    u_int mon_numero;
    char action;
    int saisie_nb;
    bool fin_tour;

    /*std::cout << "Commandes :\nj : jouer une carte\np : piocher une carte\n"
              << "u : annoncer uno\nc : annoncer un contre uno\n"
              << "\nChoix des couleurs :\n1 : rouge\n2 : vert"
              << "\n3 : bleu\n4 : jaune\n"
              << std::endl;*/

    // Définit arbitrairement ici (qui je suis dans le jeu).
    mon_numero = 4;

    // Création de la partie.
    Partie jeu(MANCHE_UNIQUE, 4);

    // Parametrage personnalisé de la partie.

    jeu.set_seed(seed);

    jeu.changer_joueur(0, new JoueurIA(jeu.joueurs[0], SIMPLET, &jeu));
    jeu.changer_joueur(1, new JoueurIA(jeu.joueurs[1], MOYEN, &jeu));
    jeu.changer_joueur(2, new JoueurIA(jeu.joueurs[2], SIMPLET, &jeu));
    jeu.changer_joueur(3, new JoueurIA(jeu.joueurs[3], MOYEN, &jeu));

    // Récupération du premier message.
    // Le premier message indique le debut de la partie et la lance.
    message = jeu.update_and_get_next_message();

    // Boucle du jeu tant que la partie n'est pas terminée.
    // Si message est un pointeur NULL, il y a eu une erreur.
    while(message != NULL && message->type != FIN_PARTIE)
    {
        switch(message->type) {
            // Si le message indique l'attente de l'action d'un joueur.
            case JOUEUR_ACTION:
            {
                // Si c'est à moi de jouer.
                if(message->num_joueur == mon_numero)
                {
                    jeu.joueurs[mon_numero]->afficher_main();
                    fin_tour = false;
                    while(!fin_tour)
                    {
                        std::cout << "Carte sur la table : "
                                  << jeu.manche_courante->active << "\n" << std::endl;
                        std::cout << "Choix de l'action : ";
                        std::cin >> action;
                        switch(action)
                        {
                            case 'j':
                                std::cout << "Saisir la carte à jouer : ";
                                std::cin >> saisie_nb;
                                std::cout << std::endl;
                                if(jeu.joueurs[mon_numero]->jouer(saisie_nb))
                                {
                                    fin_tour = true;
                                }
                                break;
                            case 'p':
                                std::cout << std::endl;
                                jeu.joueurs[mon_numero]->piocher();
                                fin_tour = true;
                                break;
                            case 'u':
                                jeu.joueurs[mon_numero]->appuie_uno();
                                break;
                            case 'c':
                                std::cout << "Saisir le joueur : " << std::endl;
                                std::cin >> saisie_nb;
                                jeu.joueurs[saisie_nb]->appuie_contre_uno();
                                break;
                            default:
                                break;
                        }

                    }
                }
                else
                {
                    //jeu.joueurs[message->num_joueur].afficher_main();
                    jeu.joueurs[message->num_joueur]->action_par_defaut();
                }

            }
                break;

            case JOUEUR_CHOIX_COULEUR:
                if(message->num_joueur == mon_numero)
                {
                    std::cin >> saisie_nb;
                    Couleur couleurs[4] = {ROUGE, VERT, BLEU, JAUNE};
                    jeu.joueurs[mon_numero]->choisir_couleur(couleurs[saisie_nb-1]);
                }
                else
                {
                    jeu.joueurs[message->num_joueur]->choisir_couleur_defaut();
                }
                break;

            case DEBUT_PARTIE:
                //std::cout << "\nLa partie commence !" << std::endl;
                break;

            case DEBUT_MANCHE:
                /*std::cout << "\nUne manche vient de commencer !" << std::endl;
                std::cout << "Carte sur la table : "
                          << jeu.manche_courante->active << "\n" << std::endl;*/
                break;

            case FIN_MANCHE:
                /*std::cout << "\nUne manche s'est terminée !\n" << std::endl;
                std::cout << "Le gagnant de la manche est le joueur "
                          << message->num_joueur << "." << std::endl;
                std::cout << "\nPoints des joueurs dans la manche :" << std::endl;
                for(u_int i=0; i<jeu.nb_joueur; i++)
                {
                    std::cout << "Joueur " << i << " : " << jeu.joueurs[i].points
                              << "." << std::endl;
                }*/
                break;

            default:
                break;
        }

        message = jeu.update_and_get_next_message();
    }

    /*if(message == NULL)
    {
        std::cerr << "La partie ne s'est pas terminée correctement." << std::endl;
    }
    else
    {
        std::cout << "\nLa partie est terminée !\n" << std::endl;
        if(jeu.gagnants_partie.size()==1)
        {
            std::cout << "Le gagnant de la partie est le joueur "
                      << jeu.gagnants_partie[0] << "." << std::endl;
        }
        else
        {
            std::cout << "Les gagnants sont les joueurs ";
            for(u_int i=0; i<jeu.gagnants_partie.size(); i++)
            {
                std::cout << jeu.gagnants_partie[i] << " ";
            }
            std::cout << "." << std::endl;
        }
        std::cout << "\nPoints des joueurs dans la partie :" << std::endl;
        for(u_int i=0; i<jeu.nb_joueur; i++)
        {
            std::cout << "Joueur " << i << " : " << jeu.joueurs[i].points
                      << "." << std::endl;
        }
    }*/

    return jeu.gagnants_partie[0];
}

int main()
{

    int NB_PARTIES = 50000;

    int gagnees[4] = {0, 0, 0, 0};

    srand(time(NULL));

    for(int i=0; i<NB_PARTIES; i++)
    {
        gagnees[simu_partie(rand())]++;
    }

    std::cout << "\nResultats :\nJoueur 0 : " << gagnees[0]/(NB_PARTIES*1.0)*100
              << "\nJoueur 1 : " << gagnees[1]/(NB_PARTIES*1.0)*100
              << "\nJoueur 2 : " << gagnees[2]/(NB_PARTIES*1.0)*100
              << "\nJoueur 3 : " << gagnees[3]/(NB_PARTIES*1.0)*100 << std::endl;

    return 0;
}

