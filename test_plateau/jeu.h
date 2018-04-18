#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QQmlContext>

#include "core/partie.h"
#include "core/pioche.h"
#include "core/carte.h"
#include "core/joueur.h"
#include "core/joueuria.h"

#define INVK Q_INVOKABLE

//todo : add hand object to context at runtime and bind to class instance
class Jeu : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int compteur READ compteur WRITE setCompteur NOTIFY compteurChanged)
public:
    explicit Jeu(QObject *parent = nullptr);

    int compteur();
    void setCompteur(int i);

    void setContext(QQmlContext *ctx);

    void addObject();

signals:
    void compteurChanged();
    void playerDrawsCard(int id);
    void playerPlaysCard(int id);
    void playerPressesUNO(int id);
    
public slots:
    void drawCard();
    void pressUNO();
    void playCard();

private:
    Partie *m_partie;
    int m_compteur;

    QQmlContext *m_ctx;
};

#endif // JEU_H
