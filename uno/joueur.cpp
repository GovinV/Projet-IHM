#include "joueur.h"

Joueur::Joueur()
{
    uno = UNOSTATE_FAUX;
    points = 0;
    manche_courante = NULL;
}


int Joueur::finir_manche()
{
    Carte *c;
    int somme_cartes = 0;
    int nb_cartes_restantes = cmain.size();

    uno = UNOSTATE_FAUX;

    for(int i=0; i<nb_cartes_restantes; i++)
    {
        c = cmain.back();
        somme_cartes += c->valeur;
        cmain.pop_back();
        manche_courante->pioche->ajouter(c);
    }

    manche_courante = NULL;

    return somme_cartes;
}


void Joueur::appuie_uno()
{
    uno = UNOSTATE_EN_ATTENTE;
}


bool Joueur::appuie_contre_uno()
{
    if(cmain.size() == 1 && uno != UNOSTATE_VRAI && uno != UNOSTATE_PENALITE)
    {
        piocher(2);
        uno = UNOSTATE_PENALITE;
        return true;
    }
    else
    {
        return false;
    }
}


void Joueur::piocher()
{
    piocher(manche_courante->prends_toi_ca);
    manche_courante->joueur_pioche();
}


void Joueur::piocher(int nb_cartes)
{
    for(int i=0; i<nb_cartes; i++)
    {
        cmain.push_back(manche_courante->pioche->tirer_carte());
    }

    uno = UNOSTATE_FAUX;

    trier_main();
}


void Joueur::trier_main()
{
    std::sort(cmain.begin(),cmain.end());
}


bool Joueur::gagne()
{
    return cmain.empty();
}


void Joueur::choisir_couleur(Couleur c)
{
    if(c < ROUGE || c > JAUNE)
    {
        std::cerr << "Couleur non valide. La couleur active reste le "
                  << couleur_to_string(manche_courante->couleur_active)
                  << "."
                  << std::endl;
    }
    else
    {
        manche_courante->couleur_active = c;
    }
}


Couleur Joueur::choisir_couleur_defaut()
{
    Couleur l_couleurs_candidates[4] = {ROUGE, VERT, BLEU, JAUNE};
    Couleur choix;
    if(cmain.empty() || cmain[0]->couleur == NOIR)
    {
        choix = l_couleurs_candidates[rand()%4];
    }
    else
    {
        choix = cmain[0]->couleur;
    }
    manche_courante->couleur_active = choix;
    return choix;
}


std::vector<int> Joueur::recherche_cartes_jouables()
{
    std::vector<int> cartes_jouables;
    int nb_cartes = cmain.size();

    if(manche_courante->plus2_actif)
    {
        for(int i=0; i<nb_cartes; i++)
        {
            if(cmain[i]->type == PLUS_DEUX)
            {
                cartes_jouables.push_back(i);
            }
        }
    }
    else if(manche_courante->plus4_actif)
    {
        for(int i=0; i<nb_cartes; i++)
        {
            if(cmain[i]->type == PLUS_QUATRE)
            {
                cartes_jouables.push_back(i);
            }
        }
    }
    else
    {
        // TODO : Refactoriser ces conditions.
        for(int i=0; i<nb_cartes; i++)
        {
            if(cmain[i]->couleur == manche_courante->couleur_active
                    || cmain[i]->couleur == NOIR)
            {
                cartes_jouables.push_back(i);
            }
            else if(cmain[i]->couleur != NOIR && cmain[i]->type == manche_courante->active->type)
            {
                if(cmain[i]->type != NUMERO || cmain[i]->valeur == manche_courante->active->valeur)
                {
                    cartes_jouables.push_back(i);
                }
            }
        }
    }

    return cartes_jouables;
}


bool Joueur::jouer(int indice_carte)
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    bool indice_valide = false;
    int nb_cartes_jouables = cartes_jouables.size();

    for(int i=0; i<nb_cartes_jouables; i++)
    {
        if(cartes_jouables[i] == indice_carte)
        {
            indice_valide = true;
            break;
        }
    }

    if(indice_valide)
    {
        manche_courante->joueur_joue(cmain[indice_carte]);
        cmain.erase(cmain.begin()+indice_carte);
        if(cmain.size()==1 && uno == UNOSTATE_EN_ATTENTE)
        {
            uno = UNOSTATE_VRAI;
        }
    }

    return indice_valide;
}


void Joueur::action_par_defaut()
{
    std::vector<int> cartes_jouables = recherche_cartes_jouables();
    if(cartes_jouables.empty())
    {
        piocher();
    }
    else
    {
        jouer(cartes_jouables[0]);
    }
}


void Joueur::afficher_main()
{
    int nb_cartes = cmain.size();

    std::cerr << "Cartes en main :"  << std::endl;

    for(int i=0; i<nb_cartes; i++)
    {
       std::cerr << cmain[i] << std::endl;
    }

    std::cerr << std::endl;
}
