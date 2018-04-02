#ifndef CARD_H
#define CARD_H

#include <QObject>

enum Couleur{ROUGE, VERT, JAUNE, BLEU, NOIR};

class Card : public QObject
{
    Q_OBJECT
    // link property with read/write and notify behavior (functions)
    Q_PROPERTY(int number READ getNumber WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(Couleur couleur READ getCouleur WRITE setCouleur NOTIFY couleurChanged)
public:

    explicit Card(QObject *parent = nullptr);

    int getNumber();
    Couleur getCouleur();
    void setNumber(int n);
    void setCouleur(Couleur c);

signals:
    void numberChanged();
    void couleurChanged();

private:
    int number;
    Couleur couleur;
};

#endif // CARD_H
