#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QDebug>
#include "client/ClientTcp.h"
#include "server.h"

class Network : public QObject
{
    Q_OBJECT
    public:
        explicit Network(QObject *parent = nullptr);

        QList<QObject*> serverList;
        QList<QObject*> playersInfos;

    signals:
        void loadRoom(QString mess,int id, int player, int maxPlayer);
        void playerJoin(QString mess);
        void playerQuit(QString mess);
        void playerStatut(QString mess);

        void serverStatut(bool online);

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

        void parseRoomList(QString list);
        void parseRoomInfos(QString infos);

        ClientTcp client;
        int state;
};

#endif // NETWORK_H
