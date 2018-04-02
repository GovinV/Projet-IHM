#include "card.h"

Card::Card(QObject *parent):
    QObject(parent)
{

}

int Card::getNumber(){
    return number;
}

Couleur Card::getCouleur()
{

}

void Card::setNumber(int n){
    if(n >= 0 && n < 10){
        number = n;
        // send signal
        emit numberChanged();
    }
}

void Card::setCouleur(Couleur c)
{

}
