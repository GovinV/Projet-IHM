#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    this->state=0;
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
}

void Network::createRoom()
{
    client.UI_to_Soc("<join>");
    this->state=2;
}

void Network::joinRoom()
{
    client.UI_to_Soc("<join>");
    this->state=2;
}

void Network::quitRoom()
{
    client.UI_to_Soc("<quit>");
    this->state=0;
}

void Network::parseRoomList(QString list)
{
    /*          TO-DO
     *
     * For each room:
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


