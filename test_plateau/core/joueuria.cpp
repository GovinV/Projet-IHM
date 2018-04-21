#include "joueuria.h"


JoueurIA::JoueurIA(Joueur j, StyleIA s) : Joueur(j.num_joueur, j.infos)
{
    std::cerr << "Le joueur " << num_joueur << " est une IA" << std::endl;

    manche_courante = j.manche_courante;
    cmain = j.cmain;
    uno = j.uno;
    points = j.points;

    style = s;
}


void JoueurIA::action_par_defaut()
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    if(cartes_jouables.empty())
    {
        piocher();
    }
    else
    {
        jouer(cartes_jouables[0]);
    }
}

Couleur JoueurIA::choisir_couleur_defaut()
{
    Couleur l_couleurs_candidates[4] = {ROUGE, VERT, BLEU, JAUNE};
    Couleur choix;
    if(cmain.empty() || cmain[0]->couleur == NOIR)
    {
        choix = l_couleurs_candidates[my_rand()%4];
    }
    else
    {
        choix = cmain[0]->couleur;
    }
    manche_courante->couleur_active = choix;
    return choix;
}
