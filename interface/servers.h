#ifndef SERVERS_H
#define SERVERS_H

#include <QMetaType>
#include <QQmlListProperty>

#include <QObject>
#include <QDebug>
#include <QtQuick>
#include "server.h"

class Servers: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<Server> serverlist READ serverlist CONSTANT)

public:
    explicit Servers(QObject *parent = nullptr);

    QQmlListProperty<Server> serverlist();
    void append(Server *);
    int count() const;
    Server* at(int) const ;
    void clear();

    QList<Server*> _serverlist;

private:

    static void append(QQmlListProperty<Server> *, Server *);
    static int count(QQmlListProperty<Server> *);
    static Server* at(QQmlListProperty<Server> *, int );
    static void clear(QQmlListProperty<Server> *);

};

#endif // SERVERS_H
