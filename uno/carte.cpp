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
        case INVERSION : description = "Changement de sens ";
            break;

        case TA_GUEULE : description = "Ta gueule ";
            break;

        case PLUS_DEUX : description = "Plus 2 ";
            break;

        case JOKER : description = "Changement de couleur ";
            break;

        case PLUS_QUATRE : description = "Plus 4 ";
            break;

        case NUMERO : description = std::to_string(valeur) + " ";
            break;

        default : description = "Carte inconnue ";
            break;
    }

    description += couleur_to_string(couleur);
}

std::string couleur_to_string(Couleur c)
{
    std::string nom_couleur = "";

    switch(c)
    {
        case ROUGE:
            nom_couleur = "rouge";
            break;

        case VERT:
            nom_couleur = "vert";
            break;

        case BLEU:
            nom_couleur = "bleu";
            break;

        case JAUNE:
            nom_couleur = "jaune";
            break;

        case NOIR:
            nom_couleur = "";
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
        return c1->valeur < c2->valeur;
        /*if(c1->type < c2->type)
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
        }*/
    }
    else
    {
        return false;
    }
}
