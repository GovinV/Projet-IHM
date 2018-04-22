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
    /// Transcrit le type de la carte en une chaine de charactères.
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

    /// La description contient le type de la carte (et son chiffre pour les
    /// NUMERO) ainsi que sa couleur entre parenthèses.
    description += "("+couleur_to_string(couleur)+")";
}

std::string couleur_to_string(Couleur c)
{
    std::string nom_couleur;

    /// Transforme la couleur de la Carte en une chaine de charactères.
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

bool comparaison_cartes(const Carte *c1, const Carte *c2)
{
    /// Comparaison sur la couleur des cartes
    if(c1->couleur < c2->couleur)
    {
        return true;
    }
    /// Si les cartes ont la même couleur
    else if(c1->couleur == c2->couleur)
    {
        /// Comparaison sur le type des cartes
        if(c1->type < c2->type)
        {
            return true;
        }
        /// Si elles ont le même type
        else if(c1->type == c2->type)
        {
            /// Comparaison sur leurs valeurs
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

bool egalite_cartes(const Carte *c1, const Carte *c2)
{
    return (c1->couleur == c2->couleur &&
            c1->type == c2->type &&
            c1->valeur == c2->valeur);
}

std::ostream &operator << (std::ostream &out, const Carte *c)
{
    /// Affiche la description de la carte.
    out << c->description;
    return out;
}

std::ostream &operator << (std::ostream &out, const Carte c)
{
    /// Affiche la description de la carte.
    out << c.description;
    return out;
}

