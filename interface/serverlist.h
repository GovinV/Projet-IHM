#ifndef SERVERLIST_H
#define SERVERLIST_H

#include <QObject>
#include <QVector>

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

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem(QString name, QString id, int player,int max);
    void removeItems(int index);

private:
    QVector<ServerItem> _items;
};

#endif // SERVER_H
