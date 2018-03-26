#include "joueur.h"

Joueur::Joueur()
{
}

Joueur::Joueur(Pioche* p)
{
    for(int i=0;i<CARTES_MAIN;i++)
    {
        piocher(p);
    }
}

void Joueur::piocher(Pioche* pioche)
{
    cmain.push_back(pioche->tirerCarte());
}

void Joueur::afficherMain()
{
    std::cout << "\nCartes en main :"  << std::endl;

    for(unsigned int i=0;i<cmain.size();i++)
    {
       std::cout << cmain[i] << "\n";
    }
}


