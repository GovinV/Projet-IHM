#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>
#include "network.h"

class Settings : public QObject
{
    Q_OBJECT

    public:
        explicit Settings(QObject *parent = nullptr);
        void setClient(Network* cl);

    signals:
        void loadSize(int width, int height);
        void loadNickname(QString mess);
        void loadLangage(QString mess);
        void loadCardStyle(QString mess);
        void loadVolume(double mess);

    public slots:
        void changeSize(int width, int height);
        void changeSize(QString width, QString height);
        void changeNickname(QString mess);
        void changeLangage(QString mess);
        void changeCardStyle(QString mess);
        void changeVolume(QString mess);
        void loadSettings();

    private:
        Network* client;
        //void saveSettings();
        //void discardSettings();

};

#endif // SETTINGS_H
