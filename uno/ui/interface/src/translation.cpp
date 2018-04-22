#include "translation.h"
#include <QDebug>
#include <QGuiApplication>
#include <QDir>

Translation::Translation(QObject *parent) : QObject(parent)
{
    translator = new QTranslator(this);
}

QString Translation::getEmptyString()
{
    return  QString();
}

void Translation::selectLanguage(QString language)
{
    qDebug() << "selectLanguage: " << language;
    if(language == QString("fr"))
    {
        qApp->removeTranslator(translator);
    }
    else
    {
        if (translator->load("uno_"+language, ":/resources/translation"))
            qApp->installTranslator(translator);

    }

    emit languageChanged();
}
