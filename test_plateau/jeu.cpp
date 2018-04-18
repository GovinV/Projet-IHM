#include "jeu.h"
#include <QDebug>

Jeu::Jeu(QObject *parent) :
    QObject(parent)
{
    m_compteur = 0;
    m_partie = new Partie(MANCHE_UNIQUE,2);
    m_partie->set_seed(42);
}

int Jeu::compteur()
{
    return m_compteur;
}

void Jeu::setCompteur(int i)
{
    m_compteur = i;
    emit compteurChanged();
}

void Jeu::setEngine(QQmlApplicationEngine *engine)
{
    m_engine = engine;
}

void Jeu::setHand(Hand *h)
{
    m_hand1 = h;
}

void Jeu::addObject()
{
    Hand hand;
    hand.bindJoueur(m_partie->get_joueur(1));

    QQmlComponent comp(qmlEngine(this), QUrl::fromLocalFile("hand.qml"));
    QObject *obj = comp.create();
    QObject *model = obj->findChild<QObject*>("model");
    if(model)
        model->setProperty("list","hand_j1");
}
