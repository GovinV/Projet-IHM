#include "partie.h"


Partie::Partie(TypePartie t, int nb_j, int limite)
{
    nb_joueur = nb_j;
    type = t;
    limite_points = limite;
    manche_courante = NULL;
    nb_cartes_debut = DEFAUT_CARTES_MAIN;
    partie_lancee = false;
    pioche = new Pioche();
    seed = unsigned(std::time(0));

    for(int i=0; i<nb_joueur; i++)
    {
        joueurs.push_back(Joueur(i));
    }
}


bool Partie::partie_finie(std::vector<Joueur *> *gagnants)
{
    gagnants->clear();

    // Vérifie qu'il n'y ai pas une manche a finir. Si finir_manche ne s'est
    // pas terminé normalement, la partie n'est pas considérée comme finie.
    if(finir_manche() != 0)
    {
        return false;
    }

    for(int i=0; i<nb_joueur; i++)
    {
        switch(type)
        {
            case CLASSIQUE:
                if(joueurs[i].points > limite_points)
                {
                    gagnants->push_back(&joueurs[i]);
                }
                break;

            case MANCHE_UNIQUE:
                if(joueurs[i].points > 0)
                {
                    gagnants->push_back(&joueurs[i]);
                }
                break;

            default:
                std::cerr << "Type de partie (" << type << ") inconnue." << std::endl;
        }
    }

    if(!gagnants->empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool Partie::manche_finie(Joueur **gagnant)
{
    *gagnant = NULL;
    // On verifie qu'une manche est en cours.
    if(manche_courante == NULL)
    {
        std::cerr << "Aucune manche en cours." << std::endl;
        return false;
    }

    for(int i=0; i<nb_joueur; i++)
    {
        switch(type)
        {
            case MANCHE_UNIQUE:
            case CLASSIQUE:
                if(joueurs[i].cmain.empty())
                {
                    *gagnant = &joueurs[i];
                    break;
                }
                break;

            default:
                std::cerr << "Type de partie (" << type << ") inconnue."
                          << std::endl;
        }
    }

    if(*gagnant != NULL)
    {

        manche_courante->joueur_gagnant = (*gagnant)->num_joueur;
        return true;
    }
    else
    {
        return false;
    }
}


Manche* Partie::nouvelle_manche()
{
    // Vérifie qu'il n'y ai pas une manche a finir. Si finir_manche ne s'est
    // pas terminé normalement, alors aucune manche ne peut être commencée.
    if(finir_manche() != 0)
    {
        return NULL;
    }

    pioche->melanger(seed);
    manche_courante = new Manche(pioche, nb_joueur);
    for(int i=0; i<nb_joueur; i++)
    {
        joueurs[i].manche_courante = manche_courante;
    }
    distribution(nb_cartes_debut);
    for(int i=0; i<nb_joueur; i++)
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
        if(id_gagnant_manche < 0)
        {
            if(force)
            {
                for(int i=0; i<nb_joueur; i++)
                {
                    joueurs[i].finir_manche();
                }
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
                    for(int i=0; i<nb_joueur; i++)
                    {
                        joueurs[id_gagnant_manche].points += joueurs[i].finir_manche();
                    }
                    break;

                case MANCHE_UNIQUE:
                    for(int i=0; i<nb_joueur; i++)
                    {
                        joueurs[id_gagnant_manche].points += joueurs[i].finir_manche();
                    }
                    break;

                default:
                    std::cerr << "Type de partie (" << type << ") inconnue." << std::endl;
                    break;
            }
        }
    }

    if(valeur_retour == 0)
    {
        manche_courante = NULL;
    }

    return valeur_retour;
}


Joueur* Partie::get_joueur(int indice)
{
    if(indice >= nb_joueur)
    {
        std::cerr << "Erreur : indice de joueur (" << indice << ") trop grand."
                  << std::endl;
        exit(1);
    }
    else
    {
        return &joueurs[indice];
    }
}


void Partie::distribution(int nb_cartes)
{
    for(int i=0; i<nb_cartes; i++)
    {
        for(int j=0; j<nb_joueur; j++)
        {
            joueurs[j].piocher(1);
        }
    }
}


void Partie::set_nb_cartes_debut(int nb_cartes)
{
    if(partie_lancee)
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
    if(partie_lancee)
    {
        std::cerr << "Le seed de la partie ne peut pas être modifié après son lancement."
                  << std::endl;
    }
    else
    {
        seed = s;
    }
}


int Partie::get_seed()
{
    return seed;
}

