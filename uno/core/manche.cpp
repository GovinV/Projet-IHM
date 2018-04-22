#include "manche.h"

Manche::Manche(InfoPartie *i, Pioche *p, int nb_j, u_int joueur_debut)
{
    /// Initialisation des paramètres et objets de la manche.
    pioche = p;
    nb_joueur = nb_j;
    sens = 1;
    plus2_actif = false;
    plus4_actif = false;
    prends_toi_ca = 1;
    joueur_gagnant = -1;
    statut_manche = MANCHE_EN_COURS;
    infos = i;

    joueur_courant = joueur_debut;

    active = pioche->tirer_carte();

    /// Par simplicité la première carte doit être un NUMERO.
    while(active->type != NUMERO)
    {
        pioche->poser(active);
        active = pioche->tirer_carte();
    }

    couleur_active = active->couleur;

    /// Création d'un message indiquant que c'est au joueur_courant de jouer.
    infos->add_message({JOUEUR_ACTION, joueur_courant});

#ifdef DEBUG_NOYAU
    std::cout << "Le joueur " << joueur_courant << " commmence." << std::endl;
#endif
}


void Manche::joueur_pioche()
{
    /// Si il pioche et qu'il y avait des '+2' ou '+4' de posés, alors il a
    /// pioché en conséquence, donc les deux effets sont remis à faux.
    plus2_actif = false;
    plus4_actif = false;

    /// Nombre de cartes à piocher par défault.
    prends_toi_ca = 1;

    /// Calcul du joueur suivant.
    joueur_courant = (joueur_courant + nb_joueur + sens) % nb_joueur;

    if(statut_manche == MANCHE_EN_COURS)
    {
        /// Création d'un message indiquant à qui c'est de jouer.
        infos->add_message({JOUEUR_ACTION, joueur_courant});
    }
}


void Manche::joueur_joue(Carte *c)
{
    /// Pose la carte active sur le tas, la carte jouée devient la carte active.
    pioche->poser(active);
    active = c;
    couleur_active = active->couleur;

    /// Prise en compte de la carte jouée si elle a un effet particulier.
    switch(active->type)
    {
        case INVERSION:
            if(nb_joueur == 2)
            {
                joueur_courant = (joueur_courant + nb_joueur + sens) % nb_joueur;
            }
            else
            {
                sens *= -1;
            }
            break;

        case TA_GUEULE:
            joueur_courant = (joueur_courant + nb_joueur + sens) % nb_joueur;
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
                /// Création d'un message indiquant que le joueur doit
                /// choisir une nouvelle couleur.
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

    /// Calcul du joueur suivant.
    joueur_courant = (joueur_courant + nb_joueur + sens) % nb_joueur;

    if(statut_manche == MANCHE_EN_COURS)
    {
        infos->add_message({JOUEUR_ACTION, joueur_courant});
    }
}


void Manche::joueur_change_couleur(Couleur couleur, u_int num_joueur)
{
    ActionJoueur action;

    action.action = CHOISIT_COULEUR;
    action.num_joueur = num_joueur;
    action.couleur = couleur;

    /// Enregistre l'action dans l'historique.
    historique.push_back(action);

    couleur_active = couleur;
}


int Manche::joueur_suivant()
{
    return joueur_courant;
}


bool Manche::est_jouable(Carte *c)
{
    /// Si un '+2' est posé, il ne peux poser qu'un autre '+2'
    if(plus2_actif)
    {
        return c->type == PLUS_DEUX;
    }
    /// Si un '+4' est posé, il ne peux poser qu'un autre '+4'
    else if(plus4_actif)
    {
        return c->type == PLUS_QUATRE;
    }
    /// Sinon il peux poser toutes les Cartes de même couleur ou de même type
    /// que la Carte active, ainsi que les '+4' et 'JOKER'.
    else
    {
        if(c->couleur == couleur_active || c->couleur == NOIR)
        {
            return true;
        }
        else if(c->type == active->type)
        {
            if(c->type != NUMERO || c->valeur == active->valeur)
            {
                return true;
            }
        }
    }
    return false;
}

void Manche::add_action_pioche(u_int num_j, Carte *c)
{
    ActionJoueur action;

    action.action = PIOCHE;
    action.num_joueur = num_j;
    action.carte_piochee = c;

    historique.push_back(action);
}

void Manche::add_action_pose(u_int num_j, int num_c, Carte *c)
{
    ActionJoueur action;

    action.action = POSE_CARTE;
    action.num_joueur = num_j;
    action.num_carte = num_c;
    action.carte_posee = c;

    historique.push_back(action);
}


