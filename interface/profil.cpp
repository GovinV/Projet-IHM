#include "profil.h"

Profil::Profil(QObject *parent) : QObject(parent)
{
    connect(&client,SIGNAL(readingComplete(QString)),this,SLOT(receiveFromServer(QString)));
}

void Profil::cmdFromQml(int type, QString mess)
{
    switch (type) {
    case 0: //config name
        client.UI_to_Soc("name: " + mess);
        break;
    case 1: //server list
        this->state=1;
        qDebug() << "profil : list";
        client.UI_to_Soc("<list>");
        break;
    case 2: //create room
        this->state=2;
        qDebug() << "new room";
        client.UI_to_Soc("<join>");
        break;
    case 3: //join room
        this->state=2;
        qDebug() << "join room: " << mess;
        client.UI_to_Soc("<join> " + mess);
        break;
    case 4: //quit room
        this->state=1;
        qDebug() << "quit room";
        //client.UI_to_Soc("<join> " + mess);
        break;
    case 5: //edit card style
        //this->state=2;
        this->cardStyle="mess";
        //save edit
        break;
    default:
        break;
    }
}

void Profil::receiveFromServer(QString mess)
{
    qDebug() << "from Server: " << mess;
    switch (this->state) {
    case 0:
        return;
    case 1: //server list
        this->state=0;
        break;
    case 2: //create room
        //this->state=0;
        break;
    case 3: //join room
        //this->state=0;
        break;
    default:
        qDebug() << "Unknown message receive from Server: " << mess;
        break;
    }
}

void Profil::receiveFromQML(QString mess)
{
    qDebug() << "Message receive from QML: " << mess;
}
