#include "pioche.h"

Pioche::Pioche()
{
    int i;

    pile.reserve(108);

    for(i=2;i<20;i++)
    {
        pile.push_back(CarteNombre(i/2,ROUGE));
        pile.push_back(CarteNombre(i/2,VERT));
        pile.push_back(CarteNombre(i/2,BLEU));
        pile.push_back(CarteNombre(i/2,JAUNE));
    }

    pile.push_back(CarteNombre(0,ROUGE));
    pile.push_back(CarteNombre(0,VERT));
    pile.push_back(CarteNombre(0,BLEU));
    pile.push_back(CarteNombre(0,JAUNE));

    for(i=0;i<2;i++)
    {
        pile.push_back(Plus2(ROUGE));
        pile.push_back(Plus2(VERT));
        pile.push_back(Plus2(BLEU));
        pile.push_back(Plus2(JAUNE));

        pile.push_back(ChangementSens(ROUGE));
        pile.push_back(ChangementSens(VERT));
        pile.push_back(ChangementSens(BLEU));
        pile.push_back(ChangementSens(JAUNE));

        pile.push_back(TaGueule(ROUGE));
        pile.push_back(TaGueule(VERT));
        pile.push_back(TaGueule(BLEU));
        pile.push_back(TaGueule(JAUNE));
    }

    for(i=0;i<4;i++)
    {
        pile.push_back(Plus4(NOIR));

        pile.push_back(ChangementCouleur(NOIR));
    }
}

void Pioche::melanger()
{
    std::random_shuffle(pile.begin(),pile.end());//pas vraiment aleatoire
}

void Pioche::PremiereCarte()
{
    active=tirerCarte();
    while(active.couleur==NOIR)
    {
        ajouter(active);
        active=tirerCarte();
    }
}

void Pioche::afficher()
{
    for(int i=0;i<108;i++)
    {
        std::cout << pile[i] << std::endl;
    }
}


/*
 * On pioche la carte de la fin du vecteur
 * si on veut en ajouter une, on l'ajoutera au debut
 * */
Carte Pioche::tirerCarte()
{
    Carte c;

    if(pile.empty())
    {
        std::cout << "Il n'y a plus de cartes a piocher" << std::endl;
        exit(1);
    }

    c = pile.back();
    pile.pop_back();

    return c;
}

void Pioche::ajouter(Carte c)
{
    pile.insert(pile.begin(),c);
}
