#include "carte.h"

Carte::Carte(Couleur c, TypeCarte t, int v)
{
    couleur = c;
    type = t;
    valeur = v;
    init_description();
}

void Carte::init_description()
{
    switch(type)
    {
        case INVERSION : description = "Inversion ";
            break;

        case TA_GUEULE : description = "Ta gueule ";
            break;

        case PLUS_DEUX : description = "+2 ";
            break;

        case JOKER : description = "Joker ";
            break;

        case PLUS_QUATRE : description = "+4 ";
            break;

        case NUMERO : description = "Numero " + std::to_string(valeur) + " ";
            break;

        default : description = "Carte inconnue ";
            break;
    }

    description += "("+couleur_to_string(couleur)+")";
}

std::string couleur_to_string(Couleur c)
{
    std::string nom_couleur = "";

    switch(c)
    {
        case ROUGE:
            nom_couleur = "Rouge";
            break;

        case VERT:
            nom_couleur = "Vert";
            break;

        case BLEU:
            nom_couleur = "Bleu";
            break;

        case JAUNE:
            nom_couleur = "Jaune";
            break;

        case NOIR:
            nom_couleur = "Noir";
            break;

        default:
            nom_couleur = "Couleur inconnue";
            break;
    }

    return nom_couleur;
}

std::ostream &operator << (std::ostream &out, const Carte *c)
{
    out << c->description;
    return out;
}

bool comparaison_cartes(const Carte *c1, const Carte *c2)
{
    if(c1->couleur < c2->couleur)
    {
        return true;
    }
    else if(c1->couleur == c2->couleur)
    {
        if(c1->type < c2->type)
        {
            return true;
        }
        else if(c1->type == c2->type)
        {
            return c1->valeur < c2->valeur;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
