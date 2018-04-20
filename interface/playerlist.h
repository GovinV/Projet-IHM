#ifndef PLAYERLIST_H
#define PLAYERLIST_H


#include <QObject>
#include <QVector>
#include <QDebug>
#include <QAbstractItemModel>

struct PlayerItem
{
    QString name;
    QString id;
    bool ready;
};

class PlayerList: public QObject
{
    Q_OBJECT

public:

    explicit PlayerList(QObject *parent = nullptr);

    QVector<PlayerItem> items() const;

    bool setItemAt(int index, const PlayerItem & item);

    signals:
        void preItemAppended();
        void postItemAppended();

        void readyEdited(int index, bool ready);

        void preItemRemoved(int index);
        void postItemRemoved();

    public slots:
        void appendItem(QString id, QString name);
        PlayerItem getItem(int index);
        int findItem(QString id);
        void editReady(QString id, bool ready);
        void removeItems(int index);
        void clear();

    private:
        QVector<PlayerItem> _items;

};

#endif // PLAYERLIST_H
