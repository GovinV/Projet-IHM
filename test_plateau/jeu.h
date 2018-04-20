#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

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
public:
    explicit Jeu(QObject *parent = nullptr);

    Hand hands[4];

    void newPlayer(int i);
    Q_INVOKABLE void start();

signals:

private:

    //fonction de transition entre la classe et le core
    void init_deck();
    QString couleur_to_string2(Couleur c);

    Partie *m_partie;
};

#endif // JEU_H
