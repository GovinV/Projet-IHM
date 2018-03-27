#include "changementcouleur.h"

ChangementCouleur::ChangementCouleur(Couleur c)
{
    type="Carte changement de couleur " + std::to_string(c);
    couleur=c;
    numero=13;
}
