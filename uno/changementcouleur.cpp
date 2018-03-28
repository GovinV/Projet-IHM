#include "changementcouleur.h"

ChangementCouleur::ChangementCouleur(Couleur c)
{
    numero = 13;
    couleur = c;
    type = "Carte " + couleur_to_string(c) + " : changement de couleur";
}
