#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


#include <QCoreApplication>
#include <QQmlEngine>
#include <QQmlComponent>

#include "network.h"
#include "settings.h"
#include "serverlist.h"
#include "servermodel.h"
#include "playerlist.h"
#include "playermodel.h"


int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<PlayerModel>("Player", 1, 0, "PlayerModel");
    qmlRegisterUncreatableType<PlayerList>("Player", 1, 0, "PlayerList",
        QStringLiteral("PlayerList should not be created in QML"));

    qmlRegisterType<ServerModel>("Server", 1, 0, "ServerModel");
    qmlRegisterUncreatableType<ServerList>("Server", 1, 0, "ServerList",
        QStringLiteral("ServerList should not be created in QML"));

    QQmlApplicationEngine engine;
    Network network;
    Settings settings;


    settings.setClient(&network);

    QList<QObject*> cardlist;
    cardlist.append(new QObject());
    cardlist.at(0)->setProperty("path","dqzfghtf");

    QQmlContext *ctx=engine.rootContext();

    ctx->setContextProperty("network", &network);
    ctx->setContextProperty("settings", &settings);

    ctx->setContextProperty("cardListModel", QVariant::fromValue(cardlist));
    ctx->setContextProperty(QStringLiteral("serversList"), &network.serverList);
    ctx->setContextProperty(QStringLiteral("playerList"), &network.playerList);

    ctx->setContextProperty(QStringLiteral("rootItem"), &settings.translate);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    settings.loadSettings();

    return app.exec();
}
