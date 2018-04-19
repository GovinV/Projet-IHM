#include "serverlist.h"

ServerList::ServerList(QObject *parent) : QObject(parent)
{
    _items.append({"semper's server","ergthry",2,4});
    _items.append({"govin's server","ergthry",1,3});
}


QVector<ServerItem> ServerList::items() const
{
    return _items;
}

bool ServerList::setItemAt(int index, const ServerItem &item)
{
    if (index < 0 || index >= _items.size())
        return false;

    const ServerItem &oldItem = _items.at(index);
    if (item.name == oldItem.name && item.id == oldItem.id &&
            item.player == oldItem.player && item.max == oldItem.max)
        return false;

    _items[index] = item;
    return true;

}

void ServerList::appendItem(QString name, QString id, int player,int max)
{
    emit preItemAppended();

    ServerItem item;
    item.name = name;
    item.id = id;
    item.player = player;
    item.max = max;
    _items.append(item);

    emit postItemAppended();
}

void ServerList::removeItems(int index)
{
    emit preItemRemoved(index);

    _items.removeAt(index);

    emit postItemRemoved();
}
