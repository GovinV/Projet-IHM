#include "partie.h"


Partie::Partie(int nbJoueur)
{
    nb_joueur = nbJoueur;
    pioche = new Pioche();

   for(int i=0; i<nbJoueur; i++)
   {
       joueurs.push_back(Joueur(i));
   }

   seed = unsigned(std::time(0));

   std::cout << "Seed de la partie : " << seed << std::endl;
}

Partie::Partie(int nbJoueur, unsigned int s):
            Partie(nbJoueur)
{
    seed = s;
}


void Partie::distribution(int nb_cartes)
{
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
    pioche->melanger(seed);

    distribution(nb_cartes_debut);

    for(int i=0; i<nb_joueur; i++)
    {
        joueurs[i].trier_main();
        joueurs[i].afficher_main(); /// DEBUG
    }

    premiere_carte();

    std::cout << active << std::endl;
}

//TODO : les contres uno
void Partie::jouer()
{
    int sens = 1;
    plus2_actif = false;
    plus4_actif = false;
    prends_toi_ca = 1;
    joueur_courant = 0;
    Carte carte_jouee;
    Couleur couleur_active = active.couleur;

    partie_en_cours = true;

    for(int i=0;i<nb_joueur;i++)
    {
        joueurs[i].uno = true;//mis a vrai au debut comme ca la partie s'arrete pour les tests
    }

    std::cout << "Debut partie" << std::endl;

    while(partie_en_cours)
    {
        if(joueurs[joueur_courant].jouer(this, couleur_active, &carte_jouee))
        {
            pioche->ajouter(active);
            active = carte_jouee;
            couleur_active = active.couleur;

            if(joueurs[joueur_courant].gagne())
            {
                partie_en_cours = false;
            }

            switch(carte_jouee.numero)
            {
                case 10:
                    if(nb_joueur == 2)
                    {
                        joueur_courant = (joueur_courant + sens) % nb_joueur;
                    }
                    else
                    {
                        sens *= -1;
                    }
                    break;

                case 11:
                    joueur_courant = (joueur_courant + sens) % nb_joueur;
                    break;

                case 12:
                    if(!plus2_actif)
                        prends_toi_ca = 2;
                    else
                        prends_toi_ca += 2;

                    plus2_actif = true;
                    break;

                case 13:
                    couleur_active = joueurs[joueur_courant].choisir_couleur();
                    break;

                case 14:
                    if(!plus4_actif)
                        prends_toi_ca = 4;
                    else
                        prends_toi_ca += 4;

                    plus4_actif = true;

                    couleur_active = joueurs[joueur_courant].choisir_couleur(); 
                    break;
            }
            std::cout << joueur_courant << " " << joueurs[joueur_courant].nom << " a joué : " << carte_jouee << std::endl;
        }
        else// joueur pioche.
        {
            joueurs[joueur_courant].piocher(pioche,prends_toi_ca);
            plus2_actif = false;
            plus4_actif = false;

            if(prends_toi_ca == 1)//le joueur a le droit de rejouer si il tire la bonne carte
            {
                if(joueurs[joueur_courant].jouer(this, couleur_active, &carte_jouee))
                {
                    pioche->ajouter(active);
                    active = carte_jouee;
                    couleur_active = active.couleur;

                    switch(carte_jouee.numero)
                    {
                        case 10:
                            if(nb_joueur == 2)
                            {
                                joueur_courant = (joueur_courant + sens) % nb_joueur;
                            }
                            else
                            {
                                sens *= -1;
                            }
                            break;

                        case 11:
                            joueur_courant = (joueur_courant + sens) % nb_joueur;
                            break;

                        case 12:
                            prends_toi_ca = 2;
                            plus2_actif = true;
                            break;

                        case 13:
                            couleur_active = joueurs[joueur_courant].choisir_couleur();
                            break;

                        case 14:
                            prends_toi_ca = 4;
                            plus4_actif = true;
                            couleur_active = joueurs[joueur_courant].choisir_couleur();
                            break;
                    }
                }


            }

            prends_toi_ca = 1;
        }

        if(partie_en_cours)
        {
            joueur_courant = (joueur_courant + sens) % nb_joueur;

            if(joueur_courant < 0)
            {
                joueur_courant += nb_joueur;
            }
        }

    }

    std::cout << joueurs[joueur_courant].nom << " a gagne !!!!!!!!!!!!!!";
}
