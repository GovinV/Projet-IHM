#ifndef NETWORK_H
#define NETWORK_H

#include <QMetaType>
#include <QQmlListProperty>

#include <QObject>
#include <QDebug>
#include <QtQuick>
#include "client/ClientTcp.h"
#include "server.h"

class Network : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<Server> serverlist READ serverlist NOTIFY serverlistChanged )
    //Q_DECLARE_METATYPE(QQmlListProperty<Server>)

    public:
        explicit Network(QObject *parent = nullptr);

        ~Network();

        QQmlListProperty<Server> serverlist();
        void svAppend(Server *);
        int svCount() const;
        Server *svAt(int) const ;
        void svClear();

        QList<Server*> _serverlist;
        //QList<Server*> _playersInfos;

    signals:
        void loadRoom(QString mess,int id, int player, int maxPlayer);
        void playerJoin(QString mess);
        void playerQuit(QString mess);
        void playerStatut(QString mess);

        void serverStatut(bool online);
        void serverlistChanged();

    public slots:

        void receiveFromServer(QString mess);

        void changeNickname(QString pseudo);
        void changeRoomName(QString name);
        void changeMaxPlayer(int n);
        void roomList();
        void createRoom(QString room_name);
        void joinRoom(QString room_id);
        void quitRoom();

    private:

        static void svAppend(QQmlListProperty<Server> *, Server *);
        static int svCount(QQmlListProperty<Server> *);
        static Server* svAt(QQmlListProperty<Server> *, int );
        static void svClear(QQmlListProperty<Server> *);

        void parseRoomList(QString list);
        void parseRoomInfos(QString infos);

        ClientTcp client;
};

#endif // NETWORK_H
