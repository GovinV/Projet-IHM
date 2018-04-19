#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "jeu.h"
#include "handmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<HandModel>("game.handmodel",1,0,"HandModel");
    qmlRegisterUncreatableType<Hand>("game.handmodel",1,0,"Hand",
        "Hand should never be created in QML");
    qmlRegisterType<Jeu>("game.backend", 1,0,"BackEnd");

    QQmlApplicationEngine engine;

    QQmlContext *ctx=engine.rootContext();

    Hand h1;

    ctx->setContextProperty("hand_j1",&h1);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
