#ifndef HAND_H
#define HAND_H

#include <QObject>
#include <QVector>

#include "core/joueur.h"

class Hand : public QObject
{
    Q_OBJECT
public:
    explicit Hand(QObject *parent = nullptr);

    void bindJoueur(Joueur *j);

    std::vector<Carte*> items() const;

    bool setItemAt(int index, Carte *item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItemp();

private:
    std::vector<Carte*> m_cartes;
    Joueur *m_joueur;

};

#endif // HAND_H
