#include "playermodel.h"

#include "playerlist.h"

PlayerModel::PlayerModel(QObject *parent)
    : QAbstractListModel(parent)
    , _list(nullptr)
{
}

int PlayerModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !_list)
        return 0;

    return _list->items().size();
}

QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !_list)
        return QVariant();

    const PlayerItem item = _list->items().at(index.row());
    switch (role) {
    case IdRole:
        return QVariant(item.id);
    case NameRole:
        return QVariant(item.name);
    case ReadyRole:
        return QVariant(item.ready);
    }
    return QVariant();
}
bool PlayerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!_list)
        return false;

    PlayerItem item = _list->items().at(index.row());
    switch (role) {
    case IdRole:
        item.id = value.toString();
        break;
    case NameRole:
        item.name = value.toString();
        break;
    case ReadyRole:
        qDebug() << "ReadyRole" << value.toBool();
        item.ready = value.toBool();
        break;
    }

    if (_list->setItemAt(index.row(), item)) {
        qDebug() << "dataChanged";
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    return false;
}

Qt::ItemFlags PlayerModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[NameRole] = "name";
    names[IdRole] = "id";
    names[ReadyRole] = "ready";
    return names;
}

PlayerList* PlayerModel::list() const
{
    return _list;
}

void PlayerModel::setList(PlayerList *list)
{
    beginResetModel();

    if (_list)
        _list->disconnect(this);

    _list = list;

    if (_list) {
        connect(_list, &PlayerList::preItemAppended, this, [=]() {
            const int index = _list->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(_list, &PlayerList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(_list, &PlayerList::readyEdited, this, [=](int index, bool ready) {
            setData(createIndex(index,0), (QVariant) ready, (int) ReadyRole);
        });

        connect(_list, &PlayerList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(_list, &PlayerList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}

