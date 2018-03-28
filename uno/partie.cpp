#include "partie.h"


Partie::Partie(int nbJoueur)
{
    nb_joueur = nbJoueur;
    pioche = new Pioche();

   for(int i=0; i<nbJoueur; i++)
   {
       joueurs.push_back(Joueur());
   }
}


void Partie::distribution(int nb_cartes)
{
    //std::cout << "Distribution de " << nb_cartes << " cartes " << std::endl;
    for(int i=0; i<nb_cartes; i++)
    {
        for(int j=0; j<nb_joueur; j++)
        {
            joueurs[j].piocher(pioche, 1);
        }
    }
}


void Partie::premiere_carte()
{
    active = pioche->tirer_carte();

    while(active.numero == 14)
    {
        pioche->ajouter(active);
        active = pioche->tirer_carte();
    }
}


void Partie::debut()
{
    pioche->melanger();

    distribution(nb_cartes_debut);

    for(int i=0; i<nb_joueur; i++)
    {
        joueurs[i].trier_main();
        joueurs[i].afficher_main(); /// DEBUG
    }

    premiere_carte();

    std::cout << "\n" << "Carte active : " << active << std::endl; /// DEBUG
}


void Partie::jouer()
{
    int sens = 1;
    Carte carte_jouee;
    Couleur couleur_active = active.couleur;

    partie_en_cours = true;

    std::cout << "Debut partie" << std::endl;

    while(partie_en_cours)
    {
        //std::cout << "Carte active : " << active << "\nAu tour du joueur " << joueur_courant  << std::endl; ///DEBUG

        joueurs[joueur_courant].jouer(this, active, couleur_active, &carte_jouee);

        pioche->ajouter(active);
        active = carte_jouee;
        joueur_courant = (joueur_courant+sens)%nb_joueur;
    }
}
