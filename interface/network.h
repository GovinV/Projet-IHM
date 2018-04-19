#ifndef NETWORK_H
#define NETWORK_H

#include <QMetaType>
#include <QQmlListProperty>

#include <QObject>
#include <QDebug>
#include <QtQuick>
#include "client/ClientTcp.h"

#include "serverlist.h"
#include "servermodel.h"

class Network : public QObject
{
    Q_OBJECT

    public:
        explicit Network(QObject *parent = nullptr);

        ServerList serverList;

    signals:
        void loadRoom(QString mess,int id, int player, int maxPlayer);
        void playerJoin(QString mess);
        void playerQuit(QString mess);
        void playerStatut(QString mess);

        void serverStatut(bool online);
        void serverlistChanged();

        void serverRoomNull(bool none);

    public slots:

        void receiveFromServer(QString mess);

        void changeNickname(QString pseudo);
        void changeRoomName(QString name);
        void changeMaxPlayer(int n);
        void roomList();
        void createRoom(QString room_name);
        void joinRoom(QString room_id);
        void leaveRoom();
        void quit();

    private:
/*
        static void svAppend(QQmlListProperty<Server> *, Server *);
        static int svCount(QQmlListProperty<Server> *);
        static Server* svAt(QQmlListProperty<Server> *, int );
        static void svClear(QQmlListProperty<Server> *);
*/
        void parseRoominfos(QString list);
        void parseRoomList(QString list);
        void parsePlayerList(QString infos);

        ClientTcp client;
};

#endif // NETWORK_H
