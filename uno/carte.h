#ifndef CARTE_H
#define CARTE_H

#include<iostream>


enum Couleur {ROUGE, VERT, BLEU, JAUNE, NOIR};

class Carte
{
public:
    Carte();
    Couleur couleur;
    std::string type;
};

inline std::ostream &operator<< (std::ostream &out, const Carte c)
{
    out << c.type;
    return out;
}

#endif // CARTE_H
