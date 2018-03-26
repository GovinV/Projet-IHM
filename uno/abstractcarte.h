#ifndef ABSTRACTCARTE_H
#define ABSTRACTCARTE_H

#include<iostream>


#define ROUGE 1
#define VERT 2
#define BLEU 3
#define JAUNE 4
#define NOIR 5

class AbstractCarte
{
public:
    AbstractCarte();
    int couleur;
    std::string type;
};

inline std::ostream &operator<< (std::ostream &out, const AbstractCarte c)
{
    out << c.type;
    return out;
}

#endif // ABSTRACTCARTE_H
