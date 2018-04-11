#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "profil.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Profil profil;

    QQmlContext *ctx=engine.rootContext();
    ctx->setContextProperty("profil", &profil);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    profil.sendToQML("dbuervbqlifdzbvuleizfbqui");
    profil.sendToQML("dbuervbqlifdzbvuleizfbqui");

    return app.exec();
}
