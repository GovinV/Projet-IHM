#include "tagueule.h"

TaGueule::TaGueule(Couleur c)
{
    type="Carte ta gueule " + std::to_string(c);
    couleur=c;
    numero=11;
}
