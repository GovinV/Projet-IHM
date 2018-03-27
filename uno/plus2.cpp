#include "plus2.h"


Plus2::Plus2(Couleur c)
{
    type="Carte plus 2 " + std::to_string(c);
    couleur=c;
    numero=12;
}
