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

bool Hand::setItemAt(int index, Carte *item)
{
    if(index < 0 || index >= m_joueur->cmain.size())
        return false;

    const Carte* oldItem = m_joueur->cmain.at(index);
    if(item->couleur == oldItem->couleur &&
            item->type == item->type &&
            item->valeur == item->valeur)
    {
        return false;
    }

    m_joueur->cmain[index] = item;
    return true;
}

void Hand::appendItemp()
{
    emit preItemAppended();
    Carte* item;
    m_joueur->cmain.push_back(item);
    emit postItemAppended();
}
