#include "cartenombre.h"
#include<string.h>

CarteNombre::CarteNombre(int n, Couleur c)
{
    numero=n;
    couleur=c;

    type="Carte " + std::to_string(numero); //+ " " + std::to_string(c);

}
