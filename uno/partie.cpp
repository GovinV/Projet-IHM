#include "partie.h"


Partie::Partie(TypePartie t, unsigned int nb_j, unsigned int limite)
{
    nb_joueur = nb_j;
    limite_points = limite;
    manche_courante = NULL;
    nb_cartes_debut = DEFAUT_CARTES_MAIN;
    statut_partie = PARTIE_ATTENTE_LANCEMENT;
    pioche = new Pioche();
    seed = unsigned(std::time(0));

    infos.nb_messages = 0;
    infos.num_next_message = 0;

    for(u_int i=0; i<nb_joueur; i++)
    {
        joueurs.push_back(Joueur(i, &infos));
    }

    if(t != CLASSIQUE && t != MANCHE_UNIQUE)
    {
        std::cerr << "Type de partie non implémenté. La partie sera de type "
                  << "MANCHE_UNIQUE." << std::endl;
        type = MANCHE_UNIQUE;
    }
    else
    {
        type = t;
    }

    infos.add_message({DEBUT_PARTIE, nb_joueur});
    infos.add_message({DEBUT_MANCHE, rand()%nb_joueur});
}


void Partie::start()
{
    statut_partie = PARTIE_EN_COURS;
    srand(seed);
}


bool Partie::finir_partie()
{
    // Si la partie n'est pas lancée, ou déjà terminée, elle ne peux pas être finie.
    if(statut_partie == PARTIE_TERMINEE || statut_partie == PARTIE_ATTENTE_LANCEMENT)
    {
        return false;
    }

    // Vérifie qu'il n'y ai pas une manche a finir. Si finir_manche ne s'est
    // pas terminé normalement, la partie n'est pas considérée comme finie.
    if(manche_courante != NULL && manche_courante->statut_manche != MANCHE_TERMINEE)
    {
        return false;
    }

    for(u_int i=0; i<nb_joueur; i++)
    {
        switch(type)
        {
            case CLASSIQUE:
                if(joueurs[i].points > limite_points)
                {
                    gagnants_partie.push_back(i);
                }
                break;

            case MANCHE_UNIQUE:
                if(joueurs[i].points > 0)
                {
                    gagnants_partie.push_back(i);
                }
                break;

            default:
                std::cerr << "Type de partie (" << type << ") inconnue." << std::endl;
        }
    }

    if(!gagnants_partie.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


Manche* Partie::nouvelle_manche(u_int joueur_debut)
{
    // Vérifie qu'il n'y ai pas une manche a finir. Si finir_manche ne s'est
    // pas terminé normalement, alors aucune manche ne peut être commencée.
    if(manche_courante != NULL)
    {
        return NULL;
    }

    pioche->melanger();
    manche_courante = new Manche(&infos, pioche, nb_joueur, joueur_debut);
    for(u_int i=0; i<nb_joueur; i++)
    {
        joueurs[i].manche_courante = manche_courante;
    }
    distribution(nb_cartes_debut);
    for(u_int i=0; i<nb_joueur; i++)
    {
        joueurs[i].trier_main();
    }

    return manche_courante;
}


int Partie::finir_manche(bool force)
{
    int id_gagnant_manche;
    int valeur_retour = 0;

    if(manche_courante != NULL)
    {
        id_gagnant_manche = manche_courante->joueur_gagnant;
        if(manche_courante->statut_manche != MANCHE_TERMINEE)
        {
            if(force)
            {
                for(u_int i=0; i<nb_joueur; i++)
                {
                    joueurs[i].finir_manche();
                }
                pioche->poser(manche_courante->active);
            }
            else
            {
                std::cerr << "La manche n'est pas encore terminée, terminaison annulée."
                          << "\nUtiliser finir_manche(true) pour la finir sans la prendre"
                          << " en compte.\n(Réinitialisation sans comptage des points)."
                          << std::endl;
                valeur_retour = 1;
            }
        }
        else
        {
            switch(type) {
                case CLASSIQUE:
                    for(u_int i=0; i<nb_joueur; i++)
                    {
                        joueurs[id_gagnant_manche].points += joueurs[i].finir_manche();
                    }
                    pioche->poser(manche_courante->active);
                    break;

                case MANCHE_UNIQUE:
                    for(u_int i=0; i<nb_joueur; i++)
                    {
                        joueurs[id_gagnant_manche].points += joueurs[i].finir_manche();
                    }
                    pioche->poser(manche_courante->active);
                    break;

                default:
                    std::cerr << "Type de partie (" << type << ") inconnue." << std::endl;
                    valeur_retour = 2;
                    break;
            }
        }

        if(valeur_retour == 0)
        {
            delete(manche_courante);
            manche_courante = NULL;
        }
    }
    //infos.add_message({});

    return valeur_retour;
}


void Partie::distribution(int nb_cartes)
{
    for(int i=0; i<nb_cartes; i++)
    {
        for(u_int j=0; j<nb_joueur; j++)
        {
            joueurs[j].piocher(1);
        }
    }
}


Message *Partie::update_and_get_next_message()
{
    Message *m;
    if(manche_courante != NULL && manche_courante->statut_manche == MANCHE_TERMINEE)
    {
        finir_manche();
        if(finir_partie())
        {
            infos.add_message({FIN_PARTIE, nb_joueur});
        }
        else
        {
            infos.add_message({DEBUT_MANCHE, rand()%nb_joueur});
        }
    }
    if(infos.num_next_message >= infos.nb_messages)
    {
        return NULL;
    }
    else
    {
        m = &infos.messages[infos.num_next_message];

        if(m->type == DEBUT_PARTIE)
        {
            start();
        }
        else if(m->type == DEBUT_MANCHE)
        {
            nouvelle_manche(m->num_joueur);
        }

        return &infos.messages[infos.num_next_message++];
    }
}


int Partie::get_seed()
{
    return seed;
}


void Partie::set_nb_cartes_debut(int nb_cartes)
{
    if(statut_partie != PARTIE_ATTENTE_LANCEMENT)
    {
        std::cerr << "Le nombre de cartes en début de manche ne peut pas être "
                  << "modifié en cours de partie."
                  << std::endl;
    }
    else
    {
        if(nb_cartes > 0)
        {
            nb_cartes_debut = nb_cartes;
        }
        else
        {
            std::cerr << "La partie ne peux pas commencer sans cartes." << std::endl;
        }
    }
}


void Partie::set_seed(int s)
{
    if(statut_partie != PARTIE_ATTENTE_LANCEMENT)
    {
        std::cerr << "Le seed de la partie ne peut pas être modifié après son lancement."
                  << std::endl;
    }
    else
    {
        seed = s;
    }
}


void Partie::set_limite(int limite)
{
    if(statut_partie != PARTIE_ATTENTE_LANCEMENT)
    {
        std::cerr << "La limite de points a atteindre ne peux pas être modifié"
                  << " après le début de la partie." << std::endl;
    }
    else
    {
        limite_points = limite;
    }
}


Partie::~Partie()
{
    if(pioche != NULL)
    {
        delete(pioche);
    }
}
