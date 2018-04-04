#ifndef CARTE_H
#define CARTE_H

#include<iostream>
#include<string.h>

/*
 * Changement de sens : 10
 * Ta gueule : 11
 * Plus 2 : 12
 * Changement de couleur : 13
 * Plus 4 : 14
 * */


enum Couleur {ROUGE, VERT, BLEU, JAUNE, NOIR};

class Carte
{
public:
    Carte();
    Carte(int n, Couleur c);

    Couleur couleur;
    int numero;
    std::string type;

    std::string ChoisirType();
};

inline std::string couleur_to_string(Couleur c)
{
    std::string nom_couleur;

    switch(c)
    {
        case ROUGE:
            nom_couleur = "rouge";
            break;

        case VERT:
            nom_couleur = "verte";
            break;

        case BLEU:
            nom_couleur = "bleue";
            break;

        case JAUNE:
            nom_couleur = "jaune";
            break;

        /*case NOIR:
            nom_couleur = "noire";
            break;*/
    }

    return nom_couleur;
}

// Redefinition de l'operateur << pour l'affichage du type
inline std::ostream &operator << (std::ostream &out, const Carte c)
{
    out << c.type;
    return out;
}

// Redefinition de l'operateur < (inferieur) pour la comparaison de cartes
inline bool operator < (const Carte c1, const Carte c2)
{
    if(c1.couleur < c2.couleur)
    {
        return true;
    }
    else if(c1.couleur == c2.couleur)
    {
        return c1.numero < c2.numero;
    }
    else
    {
        return false;
    }
}

#endif // CARTE_H
