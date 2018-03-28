#include "joueur.h"

Joueur::Joueur()
{
}


void Joueur::piocher(Pioche* pioche, int nb_cartes)
{
    for(int i=0; i<nb_cartes; i++)
    {
        cmain.push_back(pioche->tirer_carte());
    }
    trier_main();
}


void Joueur::trier_main()
{
    std::sort(cmain.begin(),cmain.end());
}


//TODO : doit retourner -1 si le joueur decide de piocher
int Joueur::action(std::vector<int> cartes_jouables)
{
    return cartes_jouables.front();
}


std::vector<int> Joueur::recherche_cartes_jouables(Carte active, Couleur couleur_active)
{
    int taille = cmain.size();
    std::vector<int> cartes_jouables;

    for(int i=0; i<taille; i++)
    {
        if(cmain[i].couleur == couleur_active || cmain[i].couleur == NOIR)
            cartes_jouables.push_back(i);

        else if(cmain[i].numero == active.numero)
            cartes_jouables.push_back(i);
    }

    return cartes_jouables;
}


bool Joueur::jouer(Partie* p, Carte active, Couleur couleur_active, Carte* carte_jouee)
{
    int icarte_jouee;
    bool deja_pioche = false;

    std::vector<int> cartes_jouables;

    cartes_jouables = recherche_cartes_jouables(active, couleur_active);

    if(cartes_jouables.empty())
    {
        piocher(p->pioche, 1);
        deja_pioche = true;
        trier_main();

        cartes_jouables = recherche_cartes_jouables(active, couleur_active);


        if(cartes_jouables.empty())
            return false;
    }

    icarte_jouee = action(cartes_jouables);

    if(icarte_jouee == -1)//si le joueur ne veut pas poser de cartes
    {
        if(!deja_pioche)
            piocher(p->pioche, 0);

        trier_main();
        return false;
    }
    else
    {
        *carte_jouee = cmain[icarte_jouee];
        cmain.erase(cmain.begin()+icarte_jouee);
        if(cmain.empty())
            p->partie_en_cours=false;

        return true;
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
