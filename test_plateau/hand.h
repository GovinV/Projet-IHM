#ifndef HAND_H
#define HAND_H

#include <QObject>
#include "card.h"

class Card;

class Hand : public QObject
{
    Q_OBJECT
public:
    explicit Hand(QObject *parent = nullptr);

signals:

public slots:
};

#endif // HAND_H
