#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QEventLoop>

#include "core/partie.h"
#include "core/pioche.h"
#include "core/carte.h"
#include "core/joueur.h"
#include "core/joueuria.h"
#include "hand.h"

class Jeu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int comp READ comp WRITE setComp NOTIFY compChanged)
public:
    explicit Jeu(QObject *parent = nullptr);

    // the 4 hands of the 4 players
    Hand hands[4];

    //action triggered from QML
    /**
     * @brief starts the game, initialize properties of this class
     */
    Q_INVOKABLE void start();

    /**
     * @brief player pick a card, function trigger core function and update
     * player hand in QML
     * @param i id of player
     */
    Q_INVOKABLE void piocher(int i);

    /**
     * @brief player plays card
     * @param i indice de la carte
     */
    Q_INVOKABLE void playCard(int i);

    Q_INVOKABLE void gameLoop();

    int comp(){return _comp;}
    void setComp(int i){_comp = i;}

    /**
     * @brief bind les boutons QML aux attributs correspondant de la classe
     * @param engine Le moteur de l'application à explorer
     */
    void setupBt(QQmlApplicationEngine *engine);

    /**
     * @brief Mets à jour le jeu (QML) du joueur
     * @param id_joueur l'id du joueur
     */
    void updateHand(int id_joueur);



signals:

    void compChanged();

    void cardPlayed();
public slots:
    void unoBtPressed();
private:

    //fonctions de transition entre la classe et le core

    /**
     * @brief initialisation des cartes dans qml
     */
    void init_deck();

    /**
     * @brief converti une couleur en son équivalent text
     * les équivalents correspondent aux noms de dossier des cartes
     * @param c couleur à convertir
     * @return l'initiale de la couleur
     */
    QString couleur_to_string2(Couleur c);

    // attributs

    Partie *m_partie;

    QObject *unoBt, *drawCardBt, *playCardBt;

    int _comp;
};

#endif // JEU_H
