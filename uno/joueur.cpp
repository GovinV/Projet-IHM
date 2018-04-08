#include "joueur.h"

Joueur::Joueur(int n)
{
    n_joueur = n;
    if(n==0)
    {
        nom = "Consta";
    }

    if(n==1)
    {
        nom = "Nikola";
    }

    if(n==2)
    {
        nom = "Govind";
    }

    if(n==3)
    {
        nom = "Adrien";
    }

    points = 0;
}


void Joueur::appuie_uno()
{
    uno = true;
}

void Joueur::piocher(Pioche* pioche, int nb_cartes)
{
    for(int i=0; i<nb_cartes; i++)
    {
        cmain.push_back(pioche->tirer_carte());
        std::cout << nom << " a pioché : " << cmain.back() << std::endl;
    }

    trier_main();
}

void Joueur::trier_main()
{
    std::sort(cmain.begin(),cmain.end());
}


bool Joueur::gagne()
{
    return uno == true && cmain.empty();
}

/*
 * Changement de sens : 10
 * Ta gueule : 11
 * Plus 2 : 12
 * Changement de couleur : 13
 * Plus 4 : 14
 * */

//Nicoh : ce sont les vrais regles tg et change pas
int Joueur::cartes_restantes()
{
    int somme = 0;

    for(int i=0;i<cmain.size();i++)
    {
        switch(cmain[i].numero)
        {
            case 10: somme += 10;
                break;

            case 11 : somme += 10;
                break;

            case 12 : somme += 25;//wlh j'hesitais entre 20 et 30 dsl
                break;

            case 13 : somme += 40;
                break;

            case 14 : somme += 50;
                break;

            default: somme += cmain[i].numero;
                break;
        }
    }

    return somme;
}

void Joueur::ajouter_points(int p)
{
    points = p;
}

bool Joueur::decide_piocher()
{
    return false;
}


int Joueur::action(std::vector<int> cartes_jouables)
{
    if(decide_piocher())
        return -1;
    else
        return cartes_jouables.front();
}

Couleur Joueur::choisir_couleur()
{
    return ROUGE;
}


std::vector<int> Joueur::recherche_cartes_jouables(Partie* p, Couleur couleur_active)
{
    int taille = cmain.size();

    int i;
    std::vector<int> cartes_jouables;

    if(p->plus2_actif)
    {
        for(i=0; i<taille; i++)
        {
            if(cmain[i].numero == p->active.numero)
            {
                cartes_jouables.push_back(i);
            }
        }
    }
    else if(p->plus4_actif)
    {
        for(i=0; i<taille; i++)
        {
            if(cmain[i].numero == p->active.numero)
            {
                cartes_jouables.push_back(i);
            }
        }
    }
    else
    {
        for(i=0; i<taille; i++)
        {
            if(cmain[i].couleur == couleur_active || cmain[i].couleur == NOIR)
                cartes_jouables.push_back(i);

            else if(cmain[i].numero == p->active.numero)
                cartes_jouables.push_back(i);
        }
    }

    return cartes_jouables;
}

//si false alors le joueur pioche, si vrai le joueur a joue une carte
bool Joueur::jouer(Partie* p, Couleur couleur_active, Carte* carte_jouee)
{
    int icarte_jouee;
    std::vector<int> cartes_jouables;

    cartes_jouables = recherche_cartes_jouables(p, couleur_active);

    if(cartes_jouables.empty())
    {
        return false;
    }
    else
    {
        icarte_jouee = action(cartes_jouables);

        if(icarte_jouee == -1)//si le joueur ne veut pas poser de cartes
        {
            return false;
        }
        else
        {
            *carte_jouee = cmain[icarte_jouee];
            cmain.erase(cmain.begin()+icarte_jouee);
            return true;
        }
    }
}


void Joueur::afficher_main()
{
    int taille = cmain.size();

    std::cout << "\n" << "Cartes en main :"  << std::endl;

    for(int i=0; i<taille; i++)
    {
       std::cout << cmain[i] << std::endl;
    }
}
