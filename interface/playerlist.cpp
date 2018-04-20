#include "playerlist.h"


PlayerList::PlayerList(QObject *parent)
{
    _items.append({"vfegrhstdjygzerhstdsfw","Semper"});
    _items.append({"cegrhtyuytgrseshrtdytr","Govin"});
}

QVector<PlayerItem> PlayerList::items() const
{
    return _items;
}

bool PlayerList::setItemAt(int index, const PlayerItem &item)
{
    if (index < 0 || index >= _items.size())
        return false;

    const PlayerItem &oldItem = _items.at(index);
    if (item.id == oldItem.id && item.name == oldItem.name &&
            item.ready == oldItem.ready)
        return false;

    _items[index] = item;
    return true;
}

void PlayerList::appendItem(QString id, QString name)
{
    emit preItemAppended();

    PlayerItem item;
    item.id = id;
    item.name = name;
    item.ready = false;
    _items.append(item);

    emit postItemAppended();

}

PlayerItem PlayerList::getItem(int index)
{
    return _items.at(index);
}

int PlayerList::findItem(QString id)
{
    for (int i = 0; i < _items.size(); i++) {
        if (_items.at(i).id==id)
            return i;
    }
    return -1;

}

void PlayerList::editReady(QString id, bool ready)
{
    int index = findItem(id);
    if(index!=-1)
    {
        emit readyEdited(index,ready);
    }
}

void PlayerList::removeItems(int index)
{
    emit preItemRemoved(index);

    _items.removeAt(index);

    emit postItemRemoved();

}

void PlayerList::clear()
{
    for (int i = 0; i < _items.size(); ) {
        emit preItemRemoved(i);
        _items.removeAt(i);
        emit postItemRemoved();
    }
}
