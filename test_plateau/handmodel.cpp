#include "handmodel.h"

HandModel::HandModel(QObject *parent):
    QAbstractListModel(parent),
    m_hand(nullptr)
{

}

Couleur int_to_couleur(int i)
{
    switch(i){
    case Couleur::BLEU:
        return Couleur::BLEU;
        break;
    case Couleur::NOIR:
        return Couleur::NOIR;
        break;
    case Couleur::ROUGE:
        return Couleur::ROUGE;
        break;
    case Couleur::VERT:
        return Couleur::VERT;
        break;
    case Couleur::JAUNE:
        return Couleur::JAUNE;
        break;
    }
}

TypeCarte int_to_typecarte(int i)
{
    switch (i) {
    case TypeCarte::NUMERO:
        return TypeCarte::NUMERO;
        break;
    case TypeCarte::INVERSION:
        return TypeCarte::INVERSION;
        break;
    case TypeCarte::TA_GUEULE:
        return TypeCarte::TA_GUEULE;
        break;
    case TypeCarte::PLUS_DEUX:
        return TypeCarte::PLUS_DEUX;
        break;
    case TypeCarte::JOKER:
        return TypeCarte::JOKER;
        break;
    case TypeCarte::PLUS_QUATRE:
        return TypeCarte::PLUS_QUATRE;
        break;
    default:
        break;
    }
}

int HandModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid() || !m_hand)
        return 0;
    return m_hand->items().size();
}

QVariant HandModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || !m_hand)
        return QVariant();

    const Carte *carte = m_hand->items().at(index.row());
    switch (role) {
    case CouleurRole:
        return QVariant(carte->couleur);
        break;
    case TypeRole:
        return QVariant(carte->type);
        break;
    case ValeurRole:
        return QVariant(carte->valeur);
    default:
        break;
    }

    return QVariant();
}

bool HandModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!m_hand)
        return false;

    Carte* item = m_hand->items().at(index.row());
    switch(role){
    case CouleurRole:
        item->couleur = int_to_couleur(value.toInt());
        break;
    case TypeRole:
        item->type = int_to_typecarte(value.toInt());
        break;
    case ValeurRole:
        item->valeur = value.toInt();
        break;
    default:
        break;
    }

    if(m_hand->setItemAt(index.row(),*item))
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

QHash<int, QByteArray> HandModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[CouleurRole] = "couleur";
    roles[TypeRole] = "type";
    roles[ValeurRole] = "valeur";
    return roles;
}
