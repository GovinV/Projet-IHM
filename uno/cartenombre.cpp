#include "cartenombre.h"
#include<string.h>

CarteNombre::CarteNombre(int n, int c)
{
    numero=n;
    couleur=c;

    type="Carte " + std::to_string(numero);

}
