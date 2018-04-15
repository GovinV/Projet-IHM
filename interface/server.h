#ifndef SERVER_H
#define SERVER_H

#include <QObject>

class Server : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int player READ player WRITE setPlayer NOTIFY playerChanged)
    Q_PROPERTY(int max READ max WRITE setMax NOTIFY maxChanged)

public:
    explicit Server(QObject *parent = nullptr);
    Server(QString name, QString id, int player,int max, QObject *parent=0);

    QString name();
    void setName(QString name);
    QString id();
    void setId(QString id);
    int player();
    void setPlayer(int player);
    int max();
    void setMax(int max);


signals:
    void nameChanged();
    void idChanged();
    void playerChanged();
    void maxChanged();

private:
    QString _name;
    QString _id;
    int _player;
    int _max;
};

#endif // SERVER_H
