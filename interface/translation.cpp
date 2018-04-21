#include "translation.h"
#include <QDebug>
#include <QGuiApplication>
#include <QDir>

Translation::Translation(QObject *parent) : QObject(parent)
{
    translator_en = new QTranslator(this);
}

QString Translation::getEmptyString()
{
    return  QString();
}

void Translation::selectLanguage(QString language)
{
    qDebug() << "nop";
    if(language == QString("en"))
    {
        qDebug() << "nop";
        translator_en->load("qrc:/resources/translation/uno_en.qm");
        qApp->installTranslator(translator_en);
    }

    if(language == QString("fr"))
    {
        qApp->removeTranslator(translator_en);
    }

    emit languageChanged();
}
