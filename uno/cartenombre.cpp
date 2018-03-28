#include "cartenombre.h"

CarteNombre::CarteNombre(int n, Couleur c)
{
    numero = n;
    couleur = c;
    type = "Carte " + couleur_to_string(c) + " : " + std::to_string(numero);

}
