#include "tagueule.h"

TaGueule::TaGueule(Couleur c)
{
    numero = 11;
    couleur = c;
    type = "Carte " + couleur_to_string(c) + " : passe ton tour";
}
