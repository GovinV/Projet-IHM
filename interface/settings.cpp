#include "settings.h"

Settings::Settings(QObject *parent) : QObject(parent)
{
    client=NULL;
}

void Settings::setClient(Network *cl)
{
    client=cl;

}

void Settings::loadSettings()
{

    QSettings setting("Uno","Settings");

    if(setting.allKeys().size()==0)
    {
        changeSize(1280,800);
        changeNickname("anonymous");
        changeLangage("fr");
        changeCardStyle("none");
        changeVolume("0.0");
    }

    setting.beginGroup("Size");
    emit loadSize(setting.value("width").toInt(),setting.value("height").toInt());
    setting.endGroup();
    setting.beginGroup("Infos");
    emit loadNickname(setting.value("nickname").toString());
    if(client!=NULL)
        client->changeNickname(setting.value("nickname").toString());
    emit loadLangage(setting.value("langage").toString());
    emit loadCardStyle(setting.value("card").toString());
    emit loadVolume(setting.value("volume").toDouble());
    setting.endGroup();

    qDebug() << "Settings Loaded";
}

void Settings::changeSize(int width, int height)
{
    QSettings setting("Uno","Settings");
    setting.beginGroup("Size");
    setting.setValue("width", width);
    setting.setValue("height", height);
    setting.endGroup();

    qDebug() << "Size Changed";
}

void Settings::changeSize(QString width, QString height)
{
    changeSize(width.toInt(), height.toInt());
}


void Settings::changeNickname(QString mess)
{
    QSettings setting("Uno","Settings");
    setting.beginGroup("Infos");
    setting.setValue("nickname", mess);
    setting.endGroup();

    qDebug() << "Nickname Changed";
}

void Settings::changeLangage(QString mess)
{
    QSettings setting("Uno","Settings");
    setting.beginGroup("Infos");
    setting.setValue("langage", mess);
    setting.endGroup();

    qDebug() << "Langage Changed";

}

void Settings::changeCardStyle(QString mess)
{
    QSettings setting("Uno","Settings");
    setting.beginGroup("Infos");
    setting.setValue("card", mess);
    setting.endGroup();

    qDebug() << "Card Style Changed";

}

void Settings::changeVolume(QString mess)
{
    QSettings setting("Uno","Settings");
    setting.beginGroup("Infos");
    setting.setValue("volume", mess.toDouble());
    setting.endGroup();

    qDebug() << "Card Style Changed";
}

