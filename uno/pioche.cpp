#include "pioche.h"

Pioche::Pioche()
{
    int i;
    nbCartes = N_CARTES;

    for(i=0;i<20;i++)
    {
       pile[i] = new CarteNombre(i/2,ROUGE);
    }

    for(i=0;i<20;i++)
    {
        pile[i+20] = new CarteNombre(i/2,VERT);
    }

    for(i=0;i<20;i++)
    {
        pile[i+40] = new CarteNombre(i/2,VERT);
    }

    for(i=0;i<20;i++)
    {
        pile[i+60] = new CarteNombre(i/2,VERT);
    }

    for(i=0;i<80;i++)
        std::cout << pile.numero;

    std::cout << "pioche cree avec " << nbCartes << "cartes\n";
}
