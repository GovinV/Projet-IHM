#ifndef JOUEURIA_H
#define JOUEURIA_H

#include "joueur.h"
#include "partie.h"
#include "types.h"


/**
 * @brief StyleIA caractérise le style de jeu ou le niveau de l'IA.
 */
enum StyleIA { SIMPLET=0, MOYEN };

/**
 * @brief La classe JoueurIA représente un participant Intelligence Artificielle.
 */
class JoueurIA : public Joueur
{
public:

    /**
     * @brief Constructeur de la classe JoueurIA.
     * @param j le Joueur qui est remplacé par une IA.
     * @param s le style de l'IA (voir l'enum StyleIA).
     * @param p la partie dans laquelle va jouer l'IA.
     */
    JoueurIA(Joueur *j, StyleIA s, Partie *p);

    /**
     * @brief Choisit une action a réaliser en fonction du style de l'IA.
     */
    void action_par_defaut();

    /**
     * @brief Action réfléchie par une IA de style SIMPLET.
     *
     * Caractéristiques de l'IA :
     *
     * Si elle ne peut rien jouer elle pioche.
     *
     * Sinon elle joue la première carte qu'elle peut jouer.
     *
     * Si elle va jouer son avant dernière carte, elle pensera une fois
     * sur deux à annoncer 'uno'.
     */
    void action_par_defaut_simplet();

    /**
     * @brief Action réfléchie par une IA de style MOYEN.
     *
     * Caractéristiques de l'IA :
     *
     * Si elle ne peut rien jouer elle pioche.
     *
     * Sinon elle attribue un score à chaque carte qu'elle peut jouer en
     * favorisant la couleur courante du jeu, ou sinon la couleur où elle a
     * le plus de cartes. Si le joueur après elle a peu de cartes (1 ou 2) alors
     * elle devient agressive et toutes les cartes pièges passent prioritaires.
     */
    void action_par_defaut_moyen();

    /**
     * @brief Choisit une nouvelle couleur en fonction du style de l'IA.
     * @return la couleur choisie.
     */
    Couleur choisir_couleur_defaut();

    /**
     * @brief Couleur choisie par une IA de style SIMPLET.
     *
     * Caractéristiques de l'IA :
     *
     * Si elle n'as plus de cartes ou que des NOIR, alors la couleur est choisie
     * aléatoirement.
     *
     * Sinon la couleur choisie est la couleur de la première carte de son jeu.
     *
     * @return la couleur choisie.
     */
    Couleur choisir_couleur_simplet();

    /**
     * @brief Couleur choisie par une IA de style MOYEN.
     *
     * Caractéristiques de l'IA :
     *
     * Si elle n'as plus de cartes ou que des NOIR, alors la couleur est choisie
     * aléatoirement.
     *
     * Sinon la couleur choisie est celle dont elle à le plus de cartes dans
     * son jeu.
     *
     * @return
     */
    Couleur choisir_couleur_moyen();

 public:
    /// Le style de l'IA (ou son niveau).
    StyleIA style;

    /// La partie dans laquelle joue l'IA.
    Partie *partie;
};

#endif // JOUEURIA_H
