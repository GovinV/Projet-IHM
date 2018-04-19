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
    Q_PROPERTY(int compteur READ compteur WRITE setCompteur NOTIFY compteurChanged)
public:
    explicit Jeu(QObject *parent = nullptr);

    int compteur();
    void setCompteur(int i);

    void setEngine(QQmlApplicationEngine *engine);
    void setHand(Hand *h);

    Q_INVOKABLE void addObject();

signals:
    void compteurChanged();

private:
    Partie *m_partie;
    int m_compteur;
    Hand *m_hand1;

    QQmlApplicationEngine *m_engine;
};

#endif // JEU_H
