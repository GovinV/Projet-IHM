#include "changementsens.h"

ChangementSens::ChangementSens(Couleur c)
{
    type="Carte changement de sens " + std::to_string(c);
    couleur=c;
    numero=10;
}
