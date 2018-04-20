#include "serverlist.h"

ServerList::ServerList(QObject *parent) : QObject(parent)
{
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

ServerItem ServerList::getItem(int index)
{
    return _items.at(index);
}

int ServerList::findItem(QString id)
{
    for (int i = 0; i < _items.size(); i++) {
        if (_items.at(i).id==id)
            return i;
    }
    return -1;
}

void ServerList::editName(QString id, QString name)
{
    int index = findItem(id);
    if(index!=-1)
    {
        emit nameEdited(index,name);
    }
}

void ServerList::editPlayer(QString id, int nb)
{
    int index = findItem(id);
    if(index!=-1)
    {
        qDebug() << "old: " << _items.at(index).player << " new: " << _items.at(index).player+nb ;
        emit playerEdited(index,_items.at(index).player+nb);
    }
}

void ServerList::editMax(QString id, int nb)
{
    int index = findItem(id);
    if(index!=-1)
    {
        emit maxEdited(index,nb);
    }
}

bool ServerList::isEmpty()
{
    return _items.count()==0;
}

void ServerList::removeItems(int index)
{
    emit preItemRemoved(index);

    _items.removeAt(index);

    emit postItemRemoved();
}

void ServerList::clear()
{

    for (int i = 0; i < _items.size(); ) {
        emit preItemRemoved(i);
        _items.removeAt(i);
        emit postItemRemoved();
    }
}
