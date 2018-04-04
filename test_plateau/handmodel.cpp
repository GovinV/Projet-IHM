#include "handmodel.h"

HandModel::HandModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int HandModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return 9;
}

QVariant HandModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role){
    case SourceRole:
        return QString(QStringLiteral("qrc:/img/cards/4r.png"));
    }
    return QVariant("qrc:/img/cards/dos.png");
}

bool HandModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
}

bool HandModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
}

QHash<int, QByteArray> HandModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[SourceRole] = "sourceImg";
    return names;
}
