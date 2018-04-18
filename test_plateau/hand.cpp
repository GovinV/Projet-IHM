#include "hand.h"

Hand::Hand(QObject* parent):
    QObject(parent)
{

}

void Hand::bindJoueur(Joueur *j)
{
    m_joueur = j;
}

std::vector<Carte*> Hand::items() const
{
    return m_joueur->cmain;
}
