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

int Joueur::trouver(Carte c)
{
    for(unsigned int i=0;i<cmain.size();i++)
    {
        if(cmain[i].type.compare(0,cmain[i].type.size(),c.type)==0)
            return i;
    }

    return -1;
}

void Joueur::poser(Carte c, Pioche* p)
{
    int pos;

    pos = trouver(c);
    if(pos != -1)
    {
        p->active=c;
        cmain.erase(cmain.begin()+pos);
    }

}

bool Joueur::DroitDeJouer()
{
    return true;
}


void Joueur::jouer(Pioche* pioche)
{
    if(DroitDeJouer())
    {

    }
    else
    {
        piocher(pioche);
    }
}

void Joueur::afficherMain()
{
    std::cout << "\nCartes en main :"  << std::endl;

    for(unsigned int i=0;i<cmain.size();i++)
    {
       std::cout << cmain[i] << "\n";
    }
}


