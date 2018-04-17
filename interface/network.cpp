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
    client.UI_to_Soc("<changeroomname> " + name);
    qDebug() << "changeRoomName: " << name;
}

void Network::changeMaxPlayer(int n)
{
    client.UI_to_Soc("<changemaxplayer> " + n);
    qDebug() << "changeMaxPlayer: " << n;
}

void Network::roomList()
{
    client.UI_to_Soc("<list>");
    this->state=1;
    qDebug() << "roomList";
}

void Network::createRoom(QString room_name)
{
    client.UI_to_Soc("<create> "+ room_name);
    this->state=2;
    qDebug() << "createRoom";
}

void Network::joinRoom(QString room_id)
{
    client.UI_to_Soc("<join> " + room_id);
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
    QStringList Rooms = list.split(">");
    foreach (QString room , Rooms)
    {
        QStringList infos = room.split(":");
        serverList.append(new Server(infos.at(1),infos.at(0),infos.at(2).toInt(),infos.at(3).toInt()));
    }
    qDebug() << "parseRoomList: " << list;

}

void Network::parseRoomInfos(QString infos)
{
    QStringList myOptions;
    myOptions << "playerjoin" << "playerquit";
    
    QStringList option = infos.split(":");

    switch(myOptions.indexOf(option.at(0)))
    {
        case 0:
            emit playerJoin(option.at(1));
            break;
        case 1:
            emit playerQuit(infos);
            break;
        /* add every others options possible*/
        default:
             qDebug() << "Unknown message receive from Server: " << infos;
             break;
    }
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


