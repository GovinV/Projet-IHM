#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "network.h"
#include "settings.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Network network;
    Settings settings;

    QQmlContext *ctx=engine.rootContext();
    ctx->setContextProperty("network", &network);
    ctx->setContextProperty("settings", &settings);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    settings.loadSettings();

    return app.exec();
}
