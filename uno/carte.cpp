#include "carte.h"

Carte::Carte()
{

}

Carte::Carte(Couleur c, TypeCarte t)
{
    couleur = c;
    type = t;
    description = init_description();

    switch(type)
    {
        case INVERSION:
            valeur = VALEUR_INVERSION;
            break;

        case TA_GUEULE:
            valeur = VALEUR_TA_GUEULE;
            break;

        case PLUS_DEUX:
            valeur = VALEUR_PLUS_DEUX;
            break;

        case JOKER:
            valeur = VALEUR_JOKER;
            break;

        case PLUS_QUATRE:
            valeur = VALEUR_PLUS_QUATRE;
            break;

        default:
            valeur = 0;
            break;
    }

}

Carte::Carte(Couleur c, TypeCarte t, int v)
{
    couleur = c;
    type = t;
    valeur = v;
    description = init_description();
}

std::string Carte::init_description()
{
    std::string t;

    switch(type)
    {
        case INVERSION : t = "Changement de sens ";
            break;

        case TA_GUEULE : t = "Ta gueule ";
            break;

        case PLUS_DEUX : t = "Plus 2 ";
            break;

        case JOKER : t = "Changement de couleur ";
            break;

        case PLUS_QUATRE : t = "Plus 4 ";
            break;

        default : t = std::to_string(valeur) + " ";
            break;
    }

    return t + couleur_to_string(couleur);
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

        default:
            break;
    }

    return nom_couleur;
}

std::ostream &operator << (std::ostream &out, const Carte *c)
{
    out << c->description;
    return out;
}

bool tri_cartes(const Carte *c1, const Carte *c2)
{
    if(c1->couleur < c2->couleur)
    {
        return true;
    }
    else if(c1->couleur == c2->couleur)
    {
        return c1->valeur < c2->valeur;
    }
    else
    {
        return false;
    }
}
