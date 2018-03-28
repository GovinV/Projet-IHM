#include "changementsens.h"

ChangementSens::ChangementSens(Couleur c)
{
    numero = 10;
    couleur = c;
    type = "Carte " + couleur_to_string(c) + " : changement de sens ";
}
