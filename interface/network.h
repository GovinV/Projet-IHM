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
#include "playerlist.h"
#include "playermodel.h"

class Network : public QObject
{
    Q_OBJECT

    public:
        explicit Network(QObject *parent = nullptr);

        ServerList serverList;
        PlayerList playerList;

    signals:
        void loadRoom(QString mess,int id, int player, int maxPlayer);

        void changeMyRoomName(QString new_name);

        void serverStatut(bool online);
        void serverlistChanged();

        void tmpReady();
        void hostLeave();

        void playerlistChanged();

        void serverRoomNull(bool none);

    public slots:

        void receiveFromServer(QString mess);
        void startGame(QString infos);
        void changeNickname(QString pseudo);
        void changeRoomName(QString name);
        void changeMaxPlayer(int n);
        void roomList();
        void setReady(bool ready);
        void createRoom(QString room_name);
        void joinRoom(QString room_id);
        void leaveRoom();
        void quit();

    private:

        void addRoom(QString room);
        void addPlayer(QString room);
        void delRoom(QString room);
        void updateRoom(int type, QString room);
        void updateRoomPlace(QString room, int nb);
        void updatePlayerReady(QString room);
        void parseRoomList(QString list);
        void parsePlayerList(QString mess);

        bool inRoom;
        bool isHost;
        QString myId;
        ClientTcp client;
};

#endif // NETWORK_H
