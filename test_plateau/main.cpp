#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "jeu.h"
#include "handmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    // MODELS
    qmlRegisterType<HandModel>("game.handmodel",1,0,"HandModel");
    qmlRegisterUncreatableType<Hand>("game.handmodel",1,0,"Hand","Hand should never be created in QML");
    qmlRegisterType<Jeu>("game.backend", 1,0,"BackEnd");

    QQmlApplicationEngine engine;
    QQmlContext *ctx=engine.rootContext();

    //*************************************************
    //PLATEAU
    Jeu jeu;
    ctx->setContextProperty("hand_j0",&jeu.hands[0]);
    ctx->setContextProperty("hand_j1",&jeu.hands[1]);
    ctx->setContextProperty("hand_j2",&jeu.hands[2]);
    ctx->setContextProperty("hand_j3",&jeu.hands[3]);
    ctx->setContextProperty("game",&jeu);

    //*************************************************

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    jeu.setupBt(&engine);

    return app.exec();
}
