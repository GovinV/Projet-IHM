#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    this->state=0;

    serverList.append(new Server("Nico's Room", "9f4gdrh9s4d9ft",1,4));
    serverList.append(new Server("Govin's Room", "9f4gdrh9s4d9ft",3,3));
    serverList.append(new Server("Nico's Room", "9f4gdrh9s4d9ft",1,4));

    connect(&client,SIGNAL(readingComplete(QString)),this,SLOT(receiveFromServer(QString)));
}

void Network::receiveFromServer(QString mess)
{
    {
        qDebug() << "from Server: " << mess;
        switch (this->state) {
        case 0:     //discard message
            return;
        case 1:     //update room list
            parseRoomList(mess);
            this->state=0;
            break;
        case 2:     //update room's infos
            parseRoomInfos(mess);
            break;
        default:
            qDebug() << "Unknown message receive from Server: " << mess;
            break;
        }
    }
}

void Network::changeNickname(QString pseudo)
{
    client.UI_to_Soc("name: " + pseudo);
    qDebug() << "changeNickname: " << pseudo;
}

void Network::changeRoomName(QString name)
{
    // TO-DO
    qDebug() << "changeRoomName: " << name;
}

void Network::changeMaxPlayer(int n)
{
    // TO-DO
    qDebug() << "changeMaxPlayer: " << n;
}

void Network::roomList()
{
    client.UI_to_Soc("<list>");
    this->state=1;
    qDebug() << "roomList";
}

void Network::createRoom()
{
    client.UI_to_Soc("<create>");
    this->state=2;
    qDebug() << "createRoom";
}

void Network::joinRoom(QString room_name)
{
    client.UI_to_Soc("<join> " + room_name);
    this->state=2;
    qDebug() << "joinRoom";
}

void Network::quitRoom()
{
    client.UI_to_Soc("<quit>");
    this->state=0;
    qDebug() << "quitRoom";
}

void Network::parseRoomList(QString list)
{
    /*          TO-DO
     *
     * For each room:
     *      serverList.append(new Server("Govin's Room", "9f4gdrh9s4d9ft",3,3));
     *
     *      sinon
     *      emit loadRoom(QString mess,int id, int player, int maxPlayer);
     *
     */
    qDebug() << "parseRoomList: " << list;

}

void Network::parseRoomInfos(QString infos)
{
    /*          TO-DO
     *
     * For each info:
     *
     *      emit playerJoin(QString mess);
     * or
     *      emit playerQuit(QString mess);
     * or
     *      emit playerStatut(QString mess);
     *
     */
    qDebug() << "parseRoomInfos: " << infos;
}


