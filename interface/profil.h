#ifndef PROFIL_H
#define PROFIL_H

#include <QObject>
#include <QDebug>
#include "client/ClientTcp.h"

class Profil : public QObject
{
    Q_OBJECT
    public:
        explicit Profil(QObject *parent = nullptr);
        QString cardStyle="s5";

    signals:
        void sendToQML(QString mess);

    public slots:
        void cmdFromQml(int type, QString mess="");
        void receiveFromServer(QString mess);
        void receiveFromQML(QString mess);

    private :
        void serverList();

        ClientTcp client;
        QString pseudo="Semper";
        int state=0;

};

#endif // PROFIL_H
