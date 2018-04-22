#ifndef SERVERLIST_H
#define SERVERLIST_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <QAbstractItemModel>

struct ServerItem
{
    QString name;
    QString id;
    int player;
    int max;
};

class ServerList : public QObject
{
    Q_OBJECT

public:

    explicit ServerList(QObject *parent = nullptr);

    QVector<ServerItem> items() const;

    bool setItemAt(int index, const ServerItem & item);


signals:
    void preItemAppended();
    void postItemAppended();

    void nameEdited(int index, QString name);
    void playerEdited(int index, int nb);
    void maxEdited(int index, int nb);

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(QString name, QString id, int player,int max);
    ServerItem getItem(int index);
    int findItem(QString id);
    void editName(QString id, QString name);
    void editPlayer(QString id, int nb);
    void editMax(QString id, int nb);
    bool isEmpty();
    void removeItems(int index);
    void clear();

private:
    QVector<ServerItem> _items;
};

#endif // SERVER_H
