#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    connect(&client,SIGNAL(readingComplete(QString)),this,SLOT(receiveFromServer(QString)));
    connect(&playerList,SIGNAL(dataChanged()),this,SIGNAL(tmpReady()));
    inRoom=false;
}

void Network::receiveFromServer(QString mess)
{
    qDebug() << "from Server: " << mess;
    QStringList option = mess.split("::");
    if(option.at(0)=="List")
        parseRoomList(option.at(1));

    else if(option.at(0)=="yourid")
    {
        std::string sv=(option.at(1).toStdString());
        sv.pop_back();
        myId=QString::fromStdString(sv);
        qDebug()<< "My network ID: " << myId;
    }

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

    else if(option.at(0)=="players")
        parsePlayerList(option.at(1));

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

void Network::setReady()
{
    client.UI_to_Soc("<ready>\n");
    qDebug() << "setReady";
}

void Network::createRoom(QString room_name)
{
    inRoom=true;
    isHost=true;
    playerList.clear();
    client.UI_to_Soc("<create>"+ room_name +"\n");
    qDebug() << "createRoom";
}

void Network::joinRoom(QString room_id)
{
    inRoom=true;
    isHost=false;
    client.UI_to_Soc("<join> " + room_id +"\n");
    client.UI_to_Soc("<players>\n");
    qDebug() << "joinRoom";
}

void Network::leaveRoom()
{
    inRoom=false;
    isHost=false;
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
    if(inRoom && nb==-1)
    {
        if(infos.at(0)==myId)
            emit hostLeave();
        else
        {
            int id=playerList.findItem(infos.at(0));
            playerList.removeItems(id);
        }
    }
    else
        serverList.editPlayer(infos.at(0), nb);

}

void Network::updatePlayerReady(QString room)
{
    QStringList infos = room.split(":");
    qDebug() << "updatePlayerReady " <<  infos.at(1).toInt();
    playerList.editReady(infos.at(0), infos.at(1).toInt());
    emit tmpReady();
}

void Network::updateRoom(int type, QString room)
{
    QStringList infos = room.split(":");
    switch (type) {
    case 1:
        if(inRoom)
            emit changeMyRoomName(infos.at(1));
        else
            serverList.editName(infos.at(0), infos.at(1));
        break;
    case 2:
        if(!inRoom)
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

void Network::parsePlayerList(QString mess)
{
    QStringList players = mess.split(">");

    playerList.clear();

    foreach (QString player , players)
    {
        QStringList infos = player.split(":");
        if(infos.size()==2)
        {
            qDebug() << "player-> id: " << infos.at(0) <<"  name: " <<infos.at(1);
            playerList.appendItem(infos.at(0),infos.at(1));
        }
    }

    qDebug() << "parsePlayerList";
}


