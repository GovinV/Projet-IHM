#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    connect(&client,SIGNAL(readingComplete(QString)),this,SLOT(receiveFromServer(QString)));
}

void Network::receiveFromServer(QString mess)
{
    qDebug() << "from Server: " << mess;
    QStringList option = mess.split("::");
    if(option.at(0)=="List")
        parseRoomList(option.at(1));

    else if(option.at(0)=="newroom")
        addRoom(option.at(1)+":1:4");
    else if(option.at(0)=="roomdel")
        delRoom(option.at(1));

    else if(option.at(0)=="changeroomname")
        updateRoom(1,option.at(1));
    else if(option.at(0)=="changemaxplayer")
        updateRoom(2,option.at(1));

    else if(option.at(0)=="roomjoin")
        updateRoomPlace(option.at(1),1);
    else if(option.at(0)=="playerleave")
        updateRoomPlace(option.at(1),-1);

    else if(option.at(0)=="playerready")
        updatePlayerReady(option.at(1));
    else if(option.at(0)=="playerjoin")
        updateRoom(3,option.at(1));

    else if (option.at(0)=="ingame")
        qDebug() << "ingame message receive from Server: " << option.at(1);
    else if (option.at(0)=="startgame")
        qDebug() << "gamestart message receive from Server: " << option.at(1);
    else
        qDebug() << "Unknown message receive from Server: " << option.at(1);
}

void Network::changeNickname(QString pseudo)
{
    client.UI_to_Soc("name:" + pseudo +"\n");
    qDebug() << "changeNickname: " << pseudo;
}

void Network::changeRoomName(QString name)
{
    client.UI_to_Soc("<changeroomname>" + name +"\n");
    qDebug() << "changeRoomName: " << name;
}

void Network::changeMaxPlayer(int n)
{
    client.UI_to_Soc("<changemaxplayer> " + n +'\n');
    qDebug() << "changeMaxPlayer: " << n;
}

void Network::roomList()
{
    client.UI_to_Soc("<list>\n");
    qDebug() << "roomList";
}

void Network::createRoom(QString room_name)
{
    playerList.clear();
    client.UI_to_Soc("<create>"+ room_name +"\n");
    qDebug() << "createRoom";
}

void Network::joinRoom(QString room_id)
{
    client.UI_to_Soc("<join> " + room_id +"\n");
    qDebug() << "joinRoom";
}

void Network::leaveRoom()
{
    client.UI_to_Soc("<leave>\n");
    qDebug() << "leaveRoom";
}

void Network::quit()
{
    client.UI_to_Soc("<quit>\n");
    qDebug() << "quitGame";
}

void Network::startGame(QString infos)
{
    //lien vers une nouvelle classe Jeu pour style jeu actif bah t'envoie msg directe à l'objet jeu sinon tu crée l'objet jeu
    qDebug() << "startGame";
}

void Network::addRoom(QString room)
{
    QStringList infos = room.split(":");
    if(infos.length()>3)
    {
        serverList.appendItem(infos.at(1),infos.at(0),infos.at(2).toInt(),infos.at(3).toInt());
        emit serverRoomNull(false);
        emit serverlistChanged();
    }
    qDebug() << "addRoom: " << room;

}

void Network::addPlayer(QString room)
{
    qDebug() << room;
}

void Network::delRoom(QString room)
{
    std::string sv=room.toStdString();
    sv.pop_back();
    int id=serverList.findItem(QString::fromStdString(sv));
    if(id==-1)
        qDebug() << "Erreur delRoom : " << room;
    else
    {
        serverList.removeItems(id);
        qDebug() << "del room : " << serverList.isEmpty();
        emit serverRoomNull(serverList.isEmpty());
    }
}

void Network::updateRoomPlace(QString room, int nb)
{
    QStringList infos = room.split(":");
    serverList.editPlayer(infos.at(0), nb);
}

void Network::updatePlayerReady(QString room)
{
    QStringList infos = room.split(":");
    playerList.editReady(infos.at(0), infos.at(1).toInt());
}

void Network::updateRoom(int type, QString room)
{
    QStringList infos = room.split(":");
    switch (type) {
    case 1:
        serverList.editName(infos.at(0), infos.at(1));
        break;
    case 2:
        serverList.editMax(infos.at(0), infos.at(1).toInt());
        break;
    case 3:
        qDebug() << "playerjoin";
        playerList.appendItem(infos.at(0),infos.at(1));
        emit playerlistChanged();
        break;
    default:
        break;
    }
}



void Network::parseRoomList(QString list)
{
    serverList.clear();
    if(list=="<no room>\n")
    {
        emit serverRoomNull(true);
        emit serverlistChanged();
        return;
    }
    QStringList Rooms = list.split(">");
    foreach (QString room , Rooms)
    {
        QStringList infos = room.split(":");
        qDebug() << "test: " + infos.at(0);
        if(infos.length()>3)
        {
            qDebug() << "test: " + infos.at(1);
            serverList.appendItem(infos.at(1),infos.at(0),infos.at(2).toInt(),infos.at(3).toInt());
        }
    }
    emit serverRoomNull(false);
    emit serverlistChanged();
    qDebug() << "parseRoomList: " << list;
}

void Network::parsePlayerList(QString infos)
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
    qDebug() << "parsePlayerList: " << infos;
}


