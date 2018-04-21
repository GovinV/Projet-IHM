#ifndef PIOCHE_H
#define PIOCHE_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "carte.h"
#include "types.h"



class Pioche
{
public:
    /**
     * @brief Constructeur de la classe Pioche.
     *
     * Créé les 108 Cartes du jeu et les ajoute à la pile.
     */
    Pioche();

    /**
     * @brief Destructeur de la classe Pioche.
     *
     * Libère la mémoire allouée à toutes les Cartes.
     */
    ~Pioche();

    /**
     * @brief Melange la pile de Cartes.
     */
    void melanger();

    /**
     * @brief Tire une Carte de la pile et la renvoie.
     *
     * Si la pile est vide, le tas est récupéré, mélangé,
     * et forme une nouvelle pile.
     *
     * @return la Carte tirée.
     */
    Carte* tirer_carte();

    /**
     * @brief Pose une Carte sur le tas.
     * @param c la carte à poser.
     */
    void poser(Carte *c);

    /**
     * @brief Ramasse le tas et le remet dans la pile.
     */
    void ramasser();

    /**
     * @brief Affiche la pioche sur la sortie standard.
     */
    void afficher();

public:
    /// Vector représentant la pile d'une partie (cartes à piocher).
    std::vector<Carte*> pile;
    /// Vector représentant le tas d'une partie (cartes jouées).
    std::vector<Carte*> tas;
};


#endif // PIOCHE_H
