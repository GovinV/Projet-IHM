#ifndef CARTE_H
#define CARTE_H

#include<iostream>
#include<string.h>


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
    /// Constructeurs.
    Carte();
    Carte(Couleur c, TypeCarte t);
    Carte(Couleur c, TypeCarte t, int v);

    /// Initialisation de la chaine de caractères décrivant la Carte.
    std::string init_description();


public:
    /// Couleur de la carte.
    Couleur couleur;
    /// Description de la carte.
    std::string description;
    /// Type de la carte.
    TypeCarte type;
    /// Valeur de la carte pour le comptage des points.
    int valeur;
};


/// Renvoie sous forme d'une chaine de caractère la couleur de la carte
/// (si elle n'est pas noire).
std::string couleur_to_string(Couleur c);


/// Redéfinition de l'opérateur << pour l'affichage d'une carte.
std::ostream &operator << (std::ostream &out, const Carte *c);


/// Redéfinition de l'opérateur < (inférieur) pour la comparaison des cartes.
bool operator < (const Carte c1, const Carte c2);

#endif // CARTE_H
