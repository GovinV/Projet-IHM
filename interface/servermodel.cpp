#include "servermodel.h"

#include "serverlist.h"

ServerModel::ServerModel(QObject *parent)
    : QAbstractListModel(parent)
    , _list(nullptr)
{
}

int ServerModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !_list)
        return 0;

    return _list->items().size();
}

QVariant ServerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !_list)
        return QVariant();

    const ServerItem item = _list->items().at(index.row());
    switch (role) {
    case NameRole:
        return QVariant(item.name);
    case IdRole:
        return QVariant(item.id);
    case PlayerRole:
        return QVariant(item.player);
    case MaxRole:
        return QVariant(item.max);
    }
    return QVariant();
}

bool ServerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!_list)
        return false;

    ServerItem item = _list->items().at(index.row());
    switch (role) {
    case NameRole:
        item.name = value.toString();
        break;
    case IdRole:
        item.id = value.toString();
        break;
    case PlayerRole:
        item.player = value.toInt();
        break;
    case MaxRole:
        item.max = value.toInt();
        break;
    }

    if (_list->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ServerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> ServerModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NameRole] = "name";
    names[IdRole] = "id";
    names[PlayerRole] = "player";
    names[MaxRole] = "max";
    return names;
}

ServerList* ServerModel::list() const
{
    return _list;
}

void ServerModel::setList(ServerList *list)
{
    beginResetModel();

    if (_list)
        _list->disconnect(this);

    _list = list;

    if (_list) {
        connect(_list, &ServerList::preItemAppended, this, [=]() {
            const int index = _list->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(_list, &ServerList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(_list, &ServerList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(_list, &ServerList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
