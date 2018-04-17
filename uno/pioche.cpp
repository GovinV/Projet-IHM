#include "pioche.h"

Pioche::Pioche()
{
    pile.reserve(108);

    // Ajout des cartes numeros
    // (1 à 9 deux fois par couleur et le 0 une fois par couleur).
    for(int i=1; i<20; i++)
    {
        pile.push_back(new Carte(ROUGE, NUMERO, i/2));
        pile.push_back(new Carte(VERT, NUMERO, i/2));
        pile.push_back(new Carte(BLEU, NUMERO, i/2));
        pile.push_back(new Carte(JAUNE, NUMERO, i/2));
    }

    // Ajout des cartes pieges de couleurs (deux par couleur) :
    // '+2', 'changement de sens' et 'passe ton tour'.
    for(int i=0; i<2; i++)
    {
        pile.push_back(new Carte(ROUGE, PLUS_DEUX, VALEUR_PLUS_DEUX));
        pile.push_back(new Carte(VERT, PLUS_DEUX, VALEUR_PLUS_DEUX));
        pile.push_back(new Carte(BLEU, PLUS_DEUX, VALEUR_PLUS_DEUX));
        pile.push_back(new Carte(JAUNE, PLUS_DEUX, VALEUR_PLUS_DEUX));

        pile.push_back(new Carte(ROUGE, INVERSION, VALEUR_INVERSION));
        pile.push_back(new Carte(VERT, INVERSION, VALEUR_INVERSION));
        pile.push_back(new Carte(BLEU, INVERSION, VALEUR_INVERSION));
        pile.push_back(new Carte(JAUNE, INVERSION, VALEUR_INVERSION));

        pile.push_back(new Carte(ROUGE, TA_GUEULE, VALEUR_TA_GUEULE));
        pile.push_back(new Carte(VERT, TA_GUEULE, VALEUR_TA_GUEULE));
        pile.push_back(new Carte(BLEU, TA_GUEULE, VALEUR_TA_GUEULE));
        pile.push_back(new Carte(JAUNE, TA_GUEULE, VALEUR_TA_GUEULE));
    }

    // Ajout des +4 et changement de couleur (quatre chacun).
    for(int i=0; i<4; i++)
    {
        pile.push_back(new Carte(NOIR, PLUS_QUATRE, VALEUR_PLUS_QUATRE));
        pile.push_back(new Carte(NOIR, JOKER, VALEUR_JOKER));
    }
}

void Pioche::melanger()
{
    std::random_shuffle(pile.begin(), pile.end());
}

Carte *Pioche::tirer_carte()
{
    if(pile.empty())
    {
        if(tas.empty())
        {
            std::cerr << "Erreur : Il n'y a plus de Cartes à piocher." << std::endl;
            exit(1);
        }
        else
        {
            pile.swap(tas);
            melanger();
        }
    }

    Carte *c = pile.back();
    pile.pop_back();

    return c;
}

void Pioche::poser(Carte *c)
{
    tas.push_back(c);
}

void Pioche::ramasser()
{
    // Fait des push bask dans pile pour toutes les Carte du tas.
    std::copy(tas.begin(), tas.end(), std::back_inserter(pile));
    // Vide le tas.
    tas.clear();
}

void Pioche::afficher()
{
    int taille_pile = pile.size(), taille_tas = tas.size();

    std::cout << "Liste des Cartes dans la pile : \n" << std::endl;
    for(int i=0; i<taille_pile; i++)
    {
        std::cout << pile[i] << std::endl;
    }

    std::cout << "\nListe des Cartes dans le tas : " << std::endl;
    for(int i=0; i<taille_tas; i++)
    {
        std::cout << tas[i] << std::endl;
    }
}

Pioche::~Pioche()
{
    int nb_cartes;

    // On regroupe toutes les cartes dans la pile.
    ramasser();

    nb_cartes = pile.size();

    for(int i=0; i<nb_cartes; i++)
    {
        delete(pile[i]);
    }
}
