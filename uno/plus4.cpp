#include "plus4.h"



Plus4::Plus4(Couleur c)
{
    numero = 14;
    couleur = c;
    type = "Carte " + couleur_to_string(c) + " : +4";
}
