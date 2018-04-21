#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include <string.h>
#include "types.h"


#define VALEUR_INVERSION 10
#define VALEUR_TA_GUEULE 10
#define VALEUR_PLUS_DEUX 25
#define VALEUR_JOKER 40
#define VALEUR_PLUS_QUATRE 50


/**
 * @brief Définition d'une énumération pour identifier la couleur des cartes.
 *
 * La Couleur NOIR correspond aux cartes 'PLUS 4' et 'JOKER'.
 */
enum Couleur { ROUGE, VERT, BLEU, JAUNE, NOIR };


/**
 * @brief Définition d'une énumération pour identifier les différents types de cartes.
 *
 * NUMERO est le type des cartes numérotées de 0 à 9.
 * PLUS_DEUX est le type des cartes spéciales faisant piocher 2 cartes au joueur suivant.
 * INVERSION est le type des cartes spéciales faisant changer le sens du jeu.
 * TA_GUEULE est le type des cartes spéciales faisant passer son tour au joueur suivant.
 * JOKER est le type des cartes spéciales donnant la possibilitée de changer la couleur du jeu.
 * PLUS_QUATRE est le type des cartes spéciales donnant la possibilitée de changer la
 *  couleur du jeu et faisant piocher 4 cartes au joueur suivant.
 */
enum TypeCarte { NUMERO, INVERSION, TA_GUEULE, PLUS_DEUX, JOKER, PLUS_QUATRE };


class Carte
{
public:
    /**
     * @brief Constructeur de la classe Carte.
     * @param c la Couleur de la Carte (voir enum Couleur).
     * @param t le Type de la Carte (voir enum TypeCarte).
     * @param v la valeur de la Carte (les points qu'elle rapporte).
     */
    Carte(Couleur c, TypeCarte t, int v);

    /**
     * @brief Initialisation de la chaine de caractères décrivant la Carte.
     */
    void init_description();


public:
    /// Couleur de la carte.
    Couleur couleur;
    /// Type de la carte.
    TypeCarte type;
    /// Description de la carte.
    std::string description;
    /// Valeur de la carte pour le comptage des points.
    int valeur;
};

/**
 * @brief Converti une Couleur en une chaine de charactère.
 *
 * La Couleur NOIR n'est pas convertie.
 *
 * @param c la Couleur a convertir.
 * @return la Couleur sous forme de chaine de charactère.
 */
std::string couleur_to_string(Couleur c);

/**
 * @brief Redéfinition de l'operateur << pour l'affichage des cartes.
 */
std::ostream &operator << (std::ostream &out, const Carte *c);


/**
 * @brief Fonction utilisée pour la comparaison de deux cartes afin de les trier.
 *
 * L'ordre des cartes est définit en fonction de leurs couleurs. Si elles ont
 * la même couleur, leurs ordre est définit en fonction de leurs type, et si elles
 * ont le même type, alors l'ordre est définit en fonction de leurs valeurs.
 *
 * Pour les Couleur :
 *  ROUGE < VERT < BLEU < JAUNE < NOIR
 *  (ordre de déclaration des Couleur dans l'enum Couleur)
 *
 * Pour les TypeCarte :
 *  NUMERO < INVERSION < TA_GUEULE < PLUS_DEUX < JOKER < PLUS_QUATRE
 *  (ordre de déclaration des TypeCarte dans l'enum TypeCarte)
 *
 * Pour les valeurs :
 *  Tri par ordre croissant.
 *
 * @param c1 un pointeur vers la première Carte.
 * @param c2 un pointeur vers la deuxième Carte.
 * @return vrai si la Carte c1 est strictement inférieure à la Carte c2, faux sinon.
 */
bool comparaison_cartes(const Carte *c1, const Carte *c2);

#endif // CARTE_H
