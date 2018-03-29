#include "pioche.h"

Pioche::Pioche()
{
    int i;

    pile.reserve(108);

    // Ajout des cartes numeros (1 à 9 deux fois par couleur et le 0 une fois par couleur)
    for(i=1;i<20;i++)
    {
        pile.push_back(CarteNombre(i/2,ROUGE));
        pile.push_back(CarteNombre(i/2,VERT));
        pile.push_back(CarteNombre(i/2,BLEU));
        pile.push_back(CarteNombre(i/2,JAUNE));
    }

    // Ajout des cartes pieges de couleurs (+2, changement de sens et passe ton tour)
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

    // Ajout des +4 et changement de couleur
    for(i=0;i<4;i++)
    {
        pile.push_back(Plus4(NOIR));
        pile.push_back(ChangementCouleur(NOIR));
    }
}

void Pioche::melanger()
{
   // std::srand(unsigned(std::time(0)));
    std::random_shuffle(pile.begin(),pile.end());
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
Carte Pioche::tirer_carte()
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
