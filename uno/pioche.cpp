#include "pioche.h"

/*
 * Changement de sens : 10
 * Ta gueule : 11
 * Plus 2 : 12
 * Changement de couleur : 13
 * Plus 4 : 14
 * */

Pioche::Pioche()
{
    int i;

    pile.reserve(108);

    // Ajout des cartes numeros (1 à 9 deux fois par couleur et le 0 une fois par couleur)
    for(i=1;i<20;i++)
    {
        pile.push_back(Carte(i/2,ROUGE));
        pile.push_back(Carte(i/2,VERT));
        pile.push_back(Carte(i/2,BLEU));
        pile.push_back(Carte(i/2,JAUNE));
    }

    // Ajout des cartes pieges de couleurs (+2, changement de sens et passe ton tour)
    for(i=0;i<2;i++)
    {
        pile.push_back(Carte(12,ROUGE));
        pile.push_back(Carte(12,VERT));
        pile.push_back(Carte(12,BLEU));
        pile.push_back(Carte(12,JAUNE));

        pile.push_back(Carte(10,ROUGE));
        pile.push_back(Carte(10,VERT));
        pile.push_back(Carte(10,BLEU));
        pile.push_back(Carte(10,JAUNE));

        pile.push_back(Carte(11,ROUGE));
        pile.push_back(Carte(11,VERT));
        pile.push_back(Carte(11,BLEU));
        pile.push_back(Carte(11,JAUNE));
    }

    // Ajout des +4 et changement de couleur
    for(i=0;i<4;i++)
    {
        pile.push_back(Carte(14,NOIR));
        pile.push_back(Carte(13,NOIR));
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
    if(pile.empty())
    {
        std::cout << "Il n'y a plus de cartes a piocher" << std::endl;
        exit(1);
    }

    Carte c = pile.back();
    pile.pop_back();

    return c;
}

void Pioche::ajouter(Carte c)
{
    pile.insert(pile.begin(),c);
}
