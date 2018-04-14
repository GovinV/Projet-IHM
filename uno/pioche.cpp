#include "pioche.h"

Pioche::Pioche()
{
    pile.reserve(108);

    // Ajout des cartes numeros (1 à 9 deux fois par couleur et le 0 une fois par couleur)
    for(int i=1; i<20; i++)
    {
        pile.push_back(new Carte(ROUGE, NUMERO, i/2));
        pile.push_back(new Carte(VERT, NUMERO, i/2));
        pile.push_back(new Carte(BLEU, NUMERO, i/2));
        pile.push_back(new Carte(JAUNE, NUMERO, i/2));
    }

    // Ajout des cartes pieges de couleurs (+2, changement de sens et passe ton tour)
    for(int i=0; i<2; i++)
    {
        pile.push_back(new Carte(ROUGE, PLUS_DEUX));
        pile.push_back(new Carte(VERT, PLUS_DEUX));
        pile.push_back(new Carte(BLEU, PLUS_DEUX));
        pile.push_back(new Carte(JAUNE, PLUS_DEUX));

        pile.push_back(new Carte(ROUGE, INVERSION));
        pile.push_back(new Carte(VERT, INVERSION));
        pile.push_back(new Carte(BLEU, INVERSION));
        pile.push_back(new Carte(JAUNE, INVERSION));

        pile.push_back(new Carte(ROUGE, TA_GUEULE));
        pile.push_back(new Carte(VERT, TA_GUEULE));
        pile.push_back(new Carte(BLEU, TA_GUEULE));
        pile.push_back(new Carte(JAUNE, TA_GUEULE));
    }

    // Ajout des +4 et changement de couleur
    for(int i=0; i<4; i++)
    {
        pile.push_back(new Carte(NOIR, PLUS_QUATRE));
        pile.push_back(new Carte(NOIR, JOKER));
    }
}

void Pioche::melanger(unsigned int s)
{
    std::srand(s);
    std::random_shuffle(pile.begin(), pile.end());
}

Carte *Pioche::tirer_carte()
{
    if(pile.empty())
    {
        std::cerr << "Il n'y a plus de cartes a piocher" << std::endl;
        exit(1);
    }

    Carte *c = pile.back();
    pile.pop_back();

    return c;
}

void Pioche::ajouter(Carte *c)
{
    pile.insert(pile.begin(), c);
}

void Pioche::afficher()
{
    for(int i=0;i<108;i++)
    {
        std::cout << pile[i] << std::endl;
    }
}

Pioche::~Pioche()
{
    int nb_cartes = pile.size();
    for(int i=0; i<nb_cartes; i++)
    {
        delete(pile[i]);
    }
}
