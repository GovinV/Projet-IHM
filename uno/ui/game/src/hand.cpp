#include "hand.h"

Hand::Hand(QObject* parent):
    QObject(parent)
{
    _items.append({TYPE_NB,"r",1});
    _items.append({TYPE_S_P2,"v",-1});
}

QVector<HandItem> Hand::items() const
{
    return _items;
}

bool Hand::setItemAt(int index, HandItem &item)
{
    if(index < 0 || index >= _items.size())
        return false;

    const HandItem oldItem = _items.at(index);
    if(item.color == oldItem.color &&
            item.type == item.type &&
            item.value == item.value)
    {
        return false;
    }

    _items[index] = item;
    return true;
}

void Hand::appendItem(int type, QString color, int value)
{
    emit preItemAppended();

    HandItem item;
    item.color = color;
    item.type = type;
    item.value = value;
    _items.append(item);

    emit postItemAppended();
}

void Hand::removeItem(int index)
{
    emit preItemRemoved(index);

    _items.removeAt(index);

    emit postItemRemoved();
}

void Hand::clear()
{
    for(auto i = 0; i<_items.size();)
    {
        removeItem(i);
    }
}
