#include "servers.h"

Servers::Servers(QObject *parent) : QObject(parent)
{
}

QQmlListProperty<Server> Servers::serverlist()
{
    return QQmlListProperty<Server>(this, 0, &Servers::append, &Servers::count, &Servers::at, &Servers::clear);
}

void Servers::append(Server * value)
{
    _serverlist.append(value);
}

void Servers::append(QQmlListProperty<Server> *property, Server *value)
{
    reinterpret_cast<Servers* >(property->data)->append(value);
}

int Servers::count() const
{
    return _serverlist.count();
}

int Servers::count(QQmlListProperty<Server> *property)
{
    return reinterpret_cast<Servers* >(property->data)->count();
}

Server *Servers::at(int index) const
{
    return _serverlist.at(index);
}
Server *Servers::at(QQmlListProperty<Server> *property, int index)
{
    return reinterpret_cast<Servers* >(property->data)->at(index);
}
void Servers::clear()
{
    _serverlist.clear();
}

void Servers::clear(QQmlListProperty<Server> *property)
{
    reinterpret_cast<Servers* >(property->data)->clear();
}
