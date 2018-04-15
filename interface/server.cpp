#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{

}

Server::Server(QString name, QString id, int player, int max, QObject *parent)
    : QObject(parent), _name(name), _id(id), _player(player), _max(max)
{

}

QString Server::name()
{
    return _name;
}

void Server::setName(QString name)
{
    _name=name;
}

QString Server::id()
{
    return _id;
}

void Server::setId(QString id)
{
    _id=id;
}

int Server::player()
{
    return _player;
}

void Server::setPlayer(int player)
{
    _player=player;
}


int Server::max()
{
    return _max;
}

void Server::setMax(int max)
{
    _max=max;
}
