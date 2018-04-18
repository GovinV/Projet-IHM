#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    connect(&client,SIGNAL(readingComplete(QString)),this,SLOT(receiveFromServer(QString)));
}

Network::~Network()
{
    client.UI_to_Soc("<quit>\n");
}

QQmlListProperty<Server> Network::serverlist()
{
    return QQmlListProperty<Server>(this, 0, &Network::svAppend, &Network::svCount, &Network::svAt, &Network::svClear);
    //return QQmlListProperty<Server>(this, _serverlist);
}

void Network::svAppend(Server * value)
{
    _serverlist.append(value);
}

void Network::svAppend(QQmlListProperty<Server> *property, Server *value)
{
    reinterpret_cast<Network* >(property->data)->svAppend(value);
}

int Network::svCount() const
{
    return _serverlist.count();
}

int Network::svCount(QQmlListProperty<Server> *property)
{
    return reinterpret_cast<Network* >(property->data)->svCount();
}

Server *Network::svAt(int index) const
{
    return _serverlist.at(index);
}
Server *Network::svAt(QQmlListProperty<Server> *property, int index)
{
    return reinterpret_cast<Network* >(property->data)->svAt(index);
}
void Network::svClear()
{
    _serverlist.clear();
}

void Network::svClear(QQmlListProperty<Server> *property)
{
    reinterpret_cast<Network* >(property->data)->svClear();
}


void Network::receiveFromServer(QString mess)
{
    qDebug() << "from Server: " << mess;
    QStringList option = mess.split("::");
    if(option.at(0)=="List")     //update room list
        parseRoomList(option.at(1));
    else if(option.at(0)=="players")     //update room's infos
        parseRoomInfos(option.at(1));
    else if(option.at(0)=="newroom")     //update room's infos
        parseRoomInfos(option.at(1));
    else if(option.at(0)=="roomjoin")     //update room's infos
        parseRoomList(">"+option.at(1));
    else if(option.at(0)=="playerleave")     //update room's infos
        parseRoomInfos(option.at(1));
    else if(option.at(0)=="changeroomname")     //update room's infos
        parseRoomInfos(option.at(1));
    else if(option.at(0)=="changemaxplayer")     //update room's infos
        parseRoomInfos(option.at(1));
    else if(option.at(0)=="roomdel")     //update room's infos
        parseRoomInfos(option.at(1));
    else
        qDebug() << "Unknown message receive from Server: " << option.at(1);
}

void Network::changeNickname(QString pseudo)
{
    client.UI_to_Soc("name: " + pseudo +"\n");
    qDebug() << "changeNickname: " << pseudo;
}

void Network::changeRoomName(QString name)
{
    client.UI_to_Soc("<changeroomname> " + name +"\n");
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
    client.UI_to_Soc("<create> "+ room_name +"\n");
    qDebug() << "createRoom";
}

void Network::joinRoom(QString room_id)
{
    client.UI_to_Soc("<join> " + room_id +"\n");
    qDebug() << "joinRoom";
}

void Network::quitRoom()
{
    client.UI_to_Soc("<leave>\n");
    qDebug() << "leaveRoom";
}

void Network::parseRoomList(QString list)
{
    if(list=="<no room>\n")
    {
        this->svAppend(new Server("Nico's Room", "9f4gdrh9s4d9ft",1,4));
        emit serverlistChanged();
        return;
    }
    _serverlist.clear();
    QStringList Rooms = list.split(">");
    foreach (QString room , Rooms)
    {
        QStringList infos = room.split(":");
        if(infos.length()>3)
        {
            qDebug() << "test: " + infos.at(1);
            _serverlist.append(new Server(infos.at(1),infos.at(0),infos.at(2).toInt(),infos.at(3).toInt()));
            emit serverlistChanged();
        }
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


