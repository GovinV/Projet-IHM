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


void Joueur::trierMain()
{
    std::sort(cmain.begin(),cmain.end());
}


bool Joueur::jouer(Pioche* pioche, Carte active, Couleur couleur_active, Carte* carte_jouee)
{
    int taille = cmain.size();
    int icarte_jouee;
    bool deja_pioche = false;

    std::vector<int> cartes_jouables;


    //determine les cartes que le joueur peut jouer
    for(int i=0;i<taille;i++)
    {
        if(cmain[i].couleur==couleur_active || cmain[i].couleur==NOIR)
            cartes_jouables.push_back(i);

        else if(cmain[i].numero==active.numero)
            cartes_jouables.push_back(i);
    }

    if(cartes_jouables.empty())
    {
        piocher(pioche);
        deja_pioche = true;
        trierMain();

        for(int i=0;i<taille;i++)
        {
            if(cmain[i].couleur==couleur_active || cmain[i].couleur==NOIR)
                cartes_jouables.push_back(i);

            else if(cmain[i].numero==active.numero)
                cartes_jouables.push_back(i);
        }

        if(cartes_jouables.empty())
            return false;
    }

    icarte_jouee = action(cartes_jouables);

    if(icarte_jouee == -1)//si le joueur ne veut pas poser de cartes
    {
        if(!deja_pioche)
            piocher(pioche);

        trierMain();
        return false;
    }
    else
    {
        *carte_jouee = cmain[icarte_jouee];
        cmain.erase(cmain.begin()+icarte_jouee);
        return true;
    }
}

//TODO : doit retourner -1 si le joueur decide de piocher
int Joueur::action(std::vector<int> cartes_jouables)
{
    return cartes_jouables.front();
}

void Joueur::afficherMain()
{
    std::cout << "\nCartes en main :"  << std::endl;

    for(unsigned int i=0;i<cmain.size();i++)
    {
       std::cout << cmain[i] << "\n";
    }
}


