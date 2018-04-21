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

//todo : add hand object to context at runtime and bind to class instance
class Jeu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int comp READ comp WRITE setComp NOTIFY compChanged)
public:
    explicit Jeu(QObject *parent = nullptr);

    // the 4 hands of the 4 players
    Hand hands[4];

    //action triggered from QML
    /** @brief starts the game, initialize properties of this class*/
    Q_INVOKABLE void start();

    /** @brief player pick a card, function trigger core function and update
     * player hand in QML
     * @param i id of player
     */
    Q_INVOKABLE void piocher(int i);

    /** @brief player plays card
     */
    Q_INVOKABLE void playCard(int i);

    Q_INVOKABLE void gameLoop();

    int comp(){return _comp;}
    void setComp(int i){_comp = i;}

    void setupBt(QQmlApplicationEngine *engine);

    void updateHand(int i);

    QObject *unoBt, *drawCardBt, *playCardBt;

signals:

    void compChanged();

    void cardPlayed();
public slots:
    void unoBtPressed();
private:

    //fonction de transition entre la classe et le core
    void init_deck();
    QString couleur_to_string2(Couleur c);

    //gameloop


    Partie *m_partie;

    int _comp;
};

#endif // JEU_H
