#include "manche.h"

Manche::Manche(InfoPartie *i, Pioche *p, int nb_j)
{
    // Initialisation des paramètres et objets de la manche.
    pioche = p;
    nb_joueur = nb_j;
    sens = 1;
    plus2_actif = false;
    plus4_actif = false;
    prends_toi_ca = 1;
    joueur_gagnant = -1;
    statut_manche = MANCHE_EN_COURS;
    infos = i;

    // Le joueur qui commence est déterminé aléatoirement.
    joueur_courant = rand() % nb_joueur;

    active = pioche->tirer_carte();

    // La première carte ne peux pas être un '+4', alors on la remet dans le
    // paquet jusqu'à avoir une Carte n'étant pas un +4.
    while(active->type == PLUS_QUATRE)
    {
        pioche->poser(active);
        active = pioche->tirer_carte();
    }

    couleur_active = active->couleur;

    infos->add_message({DEBUT_MANCHE, joueur_courant});
    infos->add_message({JOUEUR_ACTION, joueur_courant});

    std::cerr << "Le joueur " << joueur_courant << " commmence." << std::endl;
}


void Manche::joueur_pioche()
{
    // Si il pioche et qu'il y avait des '+2' ou '+4' de posés, alors il a
    // pioché en conséquence, donc les deux effets sont remis à faux.
    plus2_actif = false;
    plus4_actif = false;

    // Nombre de cartes à piocher par défault.
    prends_toi_ca = 1;

    // Calcul du joueur suivant.
    joueur_courant = (joueur_courant + sens) % nb_joueur;

    if(joueur_courant < 0)
    {
        joueur_courant += nb_joueur;
    }

    if(statut_manche == MANCHE_EN_COURS)
    {
        infos->add_message({JOUEUR_ACTION, joueur_courant});
    }
}


void Manche::joueur_joue(Carte *c)
{
    // Pose la carte active sur le tas, la carte jouée devient la carte active.
    pioche->poser(active);
    active = c;
    couleur_active = active->couleur;

    // Prise en compte de la carte jouée si elle a un effet particulier.
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
            if(statut_manche == MANCHE_EN_COURS)
            {
                infos->add_message({JOUEUR_CHOIX_COULEUR, joueur_courant});
            }

            break;

        case PLUS_QUATRE:
            if(!plus4_actif)
                prends_toi_ca = 4;
            else
                prends_toi_ca += 4;

            plus4_actif = true;

            if(statut_manche == MANCHE_EN_COURS)
            {
                infos->add_message({JOUEUR_CHOIX_COULEUR, joueur_courant});
            }
            break;

        default:
            break;
    }

    // Calcul du joueur suivant.
    joueur_courant = (joueur_courant + sens) % nb_joueur;

    if(joueur_courant < 0)
    {
        joueur_courant += nb_joueur;
    }

    if(statut_manche == MANCHE_EN_COURS)
    {
        infos->add_message({JOUEUR_ACTION, joueur_courant});
    }
}

int Manche::joueur_suivant()
{
    return joueur_courant;
}
