#ifndef CARTE_H
#define CARTE_H

#include<iostream>
#include<string.h>


enum Couleur {ROUGE, VERT, BLEU, JAUNE, NOIR};

class Carte
{
public:
    Carte();
    Couleur couleur;
    int numero;
    std::string type;
};

inline std::ostream &operator << (std::ostream &out, const Carte c)
{
    out << c.type;
    return out;
}

inline bool operator < (const Carte c1, const Carte c2)
{
    if(c1.couleur<c2.couleur)
        return true;

    else if(c1.couleur==c2.couleur)
        return c1.numero<c2.numero;

    else
        return false;
}

#endif // CARTE_H
