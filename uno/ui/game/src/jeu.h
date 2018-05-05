#ifndef JEU_H
#define JEU_H

#include <QObject>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QEventLoop>
#include <QDebug>
#include <QtConcurrent>

#include <QThread>
#include "core/partie.h"
#include "core/pioche.h"
#include "core/carte.h"
#include "core/joueur.h"
#include "core/joueuria.h"
#include "hand.h"

class Jeu : public QObject
{
    // read only
    Q_OBJECT

public:
    explicit Jeu(QObject *parent = nullptr);

    /**
     * @brief hands les 4 mains de 4 joueurs, permettent de remplir la vue QML
     * doivent être remplis avec joueur.cmain
     */
    Hand hands[4];

    void test();

    //fonctions de transition entre la classe et le core

    void gameLoop(Hand* hands_ptn);

    /**
     * @brief initialisation des cartes dans qml
     */
    void init_deck();

    /**
     * @brief Mets à jour le jeu (QML) du joueur
     * Quand les cartes dans le noyau changent, Jeu:: a aucun moyen de la savoir
     * Il faut donc trigger une fonction  pour update la vue
     * @param id_joueur l'id du joueur
     */
    void updateHand(int id_joueur);

    /**
     * @brief déclenche une QEvenLoop qui peut être libérée par un signal bt
     * Elle bloque l'exécution du scope appellant (exec bloque cette fonction
     * donc le scope de la fonction)
     * C'est cette fonction qui est censé remplacer le std::cin du prog console
     * @return le code du boutton pressé
     */
    int waitForBtPressed();

    void playCard(int index, int joueur);

    void drawCard(int id_joueur);

    void gameStep();
    void playerLoop();
    void iaLoop();

    void waitThread();

    /**
     * @brief converti une couleur en son équivalent text
     * les équivalents correspondent aux noms de dossier des cartes
     * @param c couleur à convertir
     * @return l'initiale de la couleur
     */
    QString couleur_to_string2(Couleur c);

    // attributs

    /****
    On a ici le numero du joueur. Il est evidement préférable d'avoir son propre jeu
    en bas de l'ecran. Or les listes de carte envoyées à qml (hands) ne peuvent pas
    changer d'emplacement (actuellement, hands[0] est en bas, et hands[1] est en haut
    (voir main et le binding qml, et main.qml) ).
    Lors de la distribution des cartes, si je suis joueur 1, il faudrai appliquer un modulo
    sur le compteur pour que hands[0] recoive le jeu de joueur[1]
    ****/
    u_int mon_numero;

    Partie *m_partie;

    Message *message;

    int saisie_nb;

    QObject *unoBt, *contreUnoBt, *drawCardBt, *playCardBt;

    QEventLoop eventLoop;

    int new_color;

    int current_card_nb ;

    bool myturn;

    bool waiting;

    int action;

    Carte * c;

signals:
    // current card values change notif
    void curCardChange(int index, QString cl,int value);
    void myTurn();
    void changeColor(QString cl);
    void playCardOk();
    void selectColor();
    void waitForIA();

public slots:

    // slots executés lorsque le bouton xBt est pressé
    void nextStepIA();
    void start();
    void unoBtPressed();
    void contreUnoBtPressed();
    void playCardBtPressed(int i); // i porte l'indice de la carte active
    void playChangeColor(int cl);
    void drawCardBtPressed();
};

#endif // JEU_H
