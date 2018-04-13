#include "manche.h"

Manche::Manche(Pioche *p, int nb_j)
{
    pioche = p;
    nb_joueur = nb_j;
    sens = 1;
    plus2_actif = false;
    plus4_actif = false;
    prends_toi_ca = 1;
    joueur_courant = rand() % nb_joueur;

    active = pioche->tirer_carte();

    // La première carte ne peux pas être un '+4'
    while(active->type == PLUS_QUATRE)
    {
        pioche->ajouter(active);
        active = pioche->tirer_carte();
    }
}


void Manche::joueur_pioche()
{
    plus2_actif = false;
    plus4_actif = false;
    prends_toi_ca = 1;
    //tours.push_back(tour_joueur());
}


void Manche::joueur_joue(Carte *c)
{
    pioche->ajouter(active);
    active = c;
    couleur_active = active->couleur;

    switch(active->type)
    {
        case INVERSION:
            if(nb_joueur == 2)
            {
                joueur_courant = (joueur_courant + sens) % nb_joueur;
            }
            else
            {
                sens *= -1;
            }
            break;

        case TA_GUEULE:
            joueur_courant = (joueur_courant + sens) % nb_joueur;
            break;

        case PLUS_DEUX:
            if(!plus2_actif)
                prends_toi_ca = 2;
            else
                prends_toi_ca += 2;

            plus2_actif = true;
            break;

        case JOKER:
            //couleur_active = joueurs[joueur_courant].choisir_couleur();
            break;

        case PLUS_QUATRE:
            if(!plus4_actif)
                prends_toi_ca = 4;
            else
                prends_toi_ca += 4;

            plus4_actif = true;

            //couleur_active = joueurs[joueur_courant].choisir_couleur();
            break;

        default:
            break;
    }

    joueur_courant = (joueur_courant + sens) % nb_joueur;

    if(joueur_courant < 0)
    {
        joueur_courant += nb_joueur;
    }
}


int Manche::gagnant()
{
    return 0;
}


int Manche::joueur_suivant()
{
    return joueur_courant;
}
