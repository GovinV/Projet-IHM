#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QEventLoop>
#include <QDebug>

#include "core/partie.h"
#include "core/pioche.h"
#include "core/carte.h"
#include "core/joueur.h"
#include "core/joueuria.h"
#include "hand.h"

class Jeu : public QObject
{
    // read only
    Q_PROPERTY(QString curCardColor READ curCardColor NOTIFY curCardColorChanged)
    Q_PROPERTY(int curCardType READ curCardType NOTIFY curCardTypeChanged)
    Q_PROPERTY(int curCardValue READ curCardValue NOTIFY curCardValueChanged)
    Q_OBJECT
public:
    explicit Jeu(QObject *parent = nullptr);

    /**
     * @brief hands les 4 mains de 4 joueurs, permettent de remplir la vue QML
     * doivent être remplis avec joueur.cmain
     */
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
     * @brief Le joueur joue une carte, utilise une fonction du noyau
     * Exemple de prog evenementiel qui marche
     * @param i indice de la carte
     */
    Q_INVOKABLE void playCard(int i);

    /**
      * L'idée avec cette fonction c'est de reprendre la boucle initialement écrite
      * dans le main du noyau. Comme on ne peux pas attendre une simple entrée clavier,
      * on doit attendre une input depuis QML
      * pour remplacer, on se sert de waitForBtPressed qui retourne le code boutton
      */
    Q_INVOKABLE void gameLoop();

    /**
     * @brief bind les boutons QML aux attributs correspondant de la classe
     * @param engine Le moteur de l'application à explorer
     */
    void setupBt(QQmlApplicationEngine *engine);

    /**
     * @brief Mets à jour le jeu (QML) du joueur
     * Quand les cartes dans le noyau changent, Jeu:: a aucun moyen de la savoir
     * Il faut donc trigger une fonction  pour update la vue
     * @param id_joueur l'id du joueur
     */
    void updateHand(int id_joueur);

    Q_INVOKABLE void test();

    /**
     * @brief déclenche une QEvenLoop qui peut être libérée par un signal bt
     * @return le code du boutton pressé
     */
    int waitForBtPressed();

    // curent card values getter
    QString curCardColor();
    int curCardType();
    int curCardValue();
    void updateCurCard();

signals:
    // current card values change notif
    void curCardColorChanged();
    void curCardTypeChanged();
    void curCardValueChanged();

public slots:

    // slots executés lorsque le bouton xBt est pressé

    void unoBtPressed();
    void contreUnoBtPressed();
    void playCardBtPressed(int i); // i porte l'indice de la carte active
    void drawCardBtPressed();

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

    QObject *unoBt, *contreUnoBt, *drawCardBt, *playCardBt;

    QEventLoop eventLoop;
    int current_card_nb ;
    int btPressed;
};

#endif // JEU_H
