#include "handmodel.h"

HandModel::HandModel(QObject *parent):
    QAbstractListModel(parent),
    _list(nullptr)
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
    if(parent.isValid() || !_list)
        return 0;
    return _list->items().size();
}

QVariant HandModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || !_list)
        return QVariant();

    const HandItem item = _list->items().at(index.row());
    switch (role) {
    case ColorRole:
        return QVariant(item.color);
        break;
    case TypeRole:
        return QVariant(item.type);
        break;
    case ValueRole:
        return QVariant(item.value);
    default:
        break;
    }

    return QVariant();
}

bool HandModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!_list)
        return false;

    HandItem item = _list->items().at(index.row());
    switch(role){
    case ColorRole:
        item.color = int_to_couleur(value.toInt());
        break;
    case TypeRole:
        item.type = int_to_typecarte(value.toInt());
        break;
    case ValueRole:
        item.value = value.toInt();
        break;
    default:
        break;
    }

    if(_list->setItemAt(index.row(),item))
    {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags HandModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> HandModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ColorRole] = "color";
    roles[TypeRole] = "type";
    roles[ValueRole] = "value";
    return roles;
}

Hand* HandModel::list() const
{
    return _list;
}

void HandModel::setList(Hand *list)
{
    beginResetModel();

    if(_list)
        _list->disconnect(this);

    _list = list;

    if(_list){
        connect(_list, &Hand::preItemAppended, this, [=](){
            const int index = _list->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(_list, &Hand::postItemAppended, this, [=]{
            endInsertRows();
        });
        connect(_list, &Hand::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(_list, &Hand::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    }
    endResetModel();
}
