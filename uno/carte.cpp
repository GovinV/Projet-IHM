#include "carte.h"

Carte::Carte()
{

}

Carte::Carte(int n, Couleur c)
{
    numero = n;
    couleur = c;
    type = choisir_type();
}

std::string Carte::choisir_type()
{
    std::string t;

    switch(numero)
    {
        case 10 : t = "Changement de sens ";
            break;

        case 11 : t = "Ta gueule ";
            break;

        case 12 : t = "Plus 2 ";
            break;

        case 13 : t = "Changement de couleur ";
            break;

        case 14 : t = "Plus 4 ";
            break;

        default : t = std::to_string(numero) + " ";
            break;
    }

    return t + couleur_to_string(couleur);
}
