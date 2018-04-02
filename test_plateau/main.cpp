#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "handmodel.h"
#include "card.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


    qmlRegisterType<HandModel>("Hand", 1,0, "HandModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
