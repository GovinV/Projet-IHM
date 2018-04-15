#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QDebug>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

    public:
        explicit Settings(QObject *parent = nullptr);
        void  loadSettings();

    signals:
        void loadSize(int width, int height);
        void loadNickname(QString mess);
        void loadLangage(QString mess);
        void loadCardStyle(QString mess);

    public slots:
        void changeSize(int width, int height);
        void changeNickname(QString mess);
        void changeLangage(QString mess);
        void changeCardStyle(QString mess);

    private:
        //void saveSettings();
        //void discardSettings();

};

#endif // SETTINGS_H
