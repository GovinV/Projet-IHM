#include "plus2.h"


Plus2::Plus2(Couleur c)
{
    numero = 12;
    couleur = c;
    type = "Carte " + couleur_to_string(c) + " : +2 ";
}
