#include "jeu.h"
#include <QDebug>

#define BT_UNO 1
#define BT_CUNO 2
#define BT_PLAY 3
#define BT_DRAW 4

Jeu::Jeu(QObject *parent) :
    QObject(parent)
{
    m_partie = new Partie(MANCHE_UNIQUE,4);
    m_partie->set_seed(42);
    m_partie->nouvelle_manche(0);
    qDebug()<<"init";
}

void Jeu::start()
{
    //hands[0].appendItem(TYPE_NB,"v",5);
    //qDebug()<<"hello";
    init_deck();
}

void Jeu::init_deck()
{

    for(unsigned int i = 0;i< m_partie->joueurs.size();i++)
    {
        updateHand(i);
    }
}


// i indice du joueur receveur
void Jeu::drawCard(int id_joueur)
{
    Carte *c = m_partie->pioche->tirer_carte();
    hands[id_joueur].appendItem(c->type,couleur_to_string2(c->couleur),c->valeur);
}

// i indice de la carte
void Jeu::playCard(int index)
{
    if(m_partie->joueurs.at(0)->jouer(index)){
        hands[0].removeItem(index);
    }
    updateCurCard();
}

void Jeu::test()
{
    qDebug()<<"exit value:";
}

void Jeu::gameLoop()
{
    // Déclaration des variables necessaires.
    Message *message;

    //int action;
    int saisie_nb;
    bool fin_tour;

    /*std::cout << "Commandes :\nj : jouer une carte\np : piocher une carte\n"
              << "u : annoncer uno\nc : annoncer un contre uno\n"
              << "\nChoix des couleurs :\n1 : rouge\n2 : vert"
              << "\n3 : bleu\n4 : jaune\n"
              << std::endl;*/

    // Définit arbitrairement ici (qui je suis dans le jeu).
    ///mon_numero = 1;

    // Création de la partie.
    //(inutile ici on le met dans le constructeur)
    ///Partie m_partie(MANCHE_UNIQUE, 2);

    // Parametrage personnalisé de la partie.
    //(idem)
    ///m_partie->set_seed(seed);

    ///m_partie->changer_joueur(0, new JoueurIA(m_partie->joueurs[0], MOYEN, &m_partie));
    /*m_partie->changer_joueur(1, new JoueurIA(m_partie->joueurs[1], MOYEN, &m_partie));
    m_partie->changer_joueur(2, new JoueurIA(m_partie->joueurs[2], SIMPLET, &m_partie));
    m_partie->changer_joueur(3, new JoueurIA(m_partie->joueurs[3], MOYEN, &m_partie));*/

    // Récupération du premier message.
    // Le premier message indique le debut de la partie et la lance.
    message = m_partie->update_and_get_next_message();

    // Boucle du m_partie tant que la partie n'est pas terminée.
    // Si message est un pointeur NULL, il y a eu une erreur.
    while(message != NULL && message->type != FIN_PARTIE)
    {
        switch(message->type) {
        // Si le message indique l'attente de l'action d'un joueur.
        case JOUEUR_ACTION:
        {
            // Si c'est à moi de jouer.
            if(message->num_joueur == mon_numero)
            {
                //m_partie->joueurs[mon_numero]->afficher_main();
                fin_tour = false;
                while(!fin_tour)
                {
                    ///std::cout << "Carte sur la table : "
                       ///       << m_partie->manche_courante->active << "\n" << std::endl;
                    std::cout << "Choix de l'action : ";
                    ///std::cin >> action;
                    ///switch(action)
                    switch(waitForBtPressed())
                    {
                    // on récupère le code boutton et on agis en fonction
                    case BT_PLAY:///'p'
                        ///std::cout << "Saisir la carte à jouer : ";
                        ///std::cin >> saisie_nb;
                        ///std::cout << std::endl;
                        if(m_partie->joueurs[mon_numero]->jouer(current_card_nb))
                        {
                            fin_tour = true;
                        }
                        break;
                    case BT_DRAW:
                        ///std::cout << std::endl;
                        ///m_partie->joueurs[mon_numero]->piocher();

                        //piocher est déjà activer par un elem QML, mais normalement
                        //elle devrait être trigger ici (ne marche pas a cause du bug connect)
                        drawCard(mon_numero);

                        fin_tour = true;
                        break;
                    case BT_UNO:
                        m_partie->joueurs[mon_numero]->appuie_uno();
                        break;
                    case BT_CUNO:
                        /** std::cout << "Saisir le joueur : " << std::endl;
                        std::cin >> saisie_nb;
                        m_partie->joueurs[saisie_nb]->appuie_contre_uno();*/
                        break;
                    default:
                        break;
                    }

                }
            }
            else
            {
                ///m_partie->joueurs[message->num_joueur]->afficher_main();
                m_partie->joueurs[message->num_joueur]->action_par_defaut();
            }

        }
            break;

        case JOUEUR_CHOIX_COULEUR:
            if(message->num_joueur == mon_numero)
            {
                std::cin >> saisie_nb;
                Couleur couleurs[4] = {ROUGE, VERT, BLEU, JAUNE};
                m_partie->joueurs[mon_numero]->choisir_couleur(couleurs[saisie_nb-1]);
            }
            else
            {
                m_partie->joueurs[message->num_joueur]->choisir_couleur_defaut();
            }
            break;

        case DEBUT_PARTIE:
            std::cout << "\nLa partie commence !" << std::endl;
            break;

        case DEBUT_MANCHE:
            std::cout << "\nUne manche vient de commencer !" << std::endl;
            std::cout << "Carte sur la table : "
                      << m_partie->manche_courante->active << "\n" << std::endl;
            break;

        case FIN_MANCHE:
            std::cout << "\nUne manche s'est terminée !\n" << std::endl;
            std::cout << "Le gagnant de la manche est le joueur "
                      << message->num_joueur << "." << std::endl;
            std::cout << "\nPoints des joueurs dans la manche :" << std::endl;
            for(u_int i=0; i<m_partie->nb_joueur; i++)
            {
                std::cout << "Joueur " << i << " : " << m_partie->joueurs[i]->points
                          << "." << std::endl;
            }
            break;

        default:
            break;
        }

        message = m_partie->update_and_get_next_message();
    }

    if(message == NULL)
    {
        std::cerr << "La partie ne s'est pas terminée correctement." << std::endl;
    }
    else
    {
        std::cout << "\nLa partie est terminée !\n" << std::endl;
        if(m_partie->gagnants_partie.size()==1)
        {
            std::cout << "Le gagnant de la partie est le joueur "
                      << m_partie->gagnants_partie[0] << "." << std::endl;
        }
        else
        {
            std::cout << "Les gagnants sont les joueurs ";
            for(u_int i=0; i<m_partie->gagnants_partie.size(); i++)
            {
                std::cout << m_partie->gagnants_partie[i] << " ";
            }
            std::cout << "." << std::endl;
        }
        std::cout << "\nPoints des joueurs dans la partie :" << std::endl;
        for(u_int i=0; i<m_partie->nb_joueur; i++)
        {
            std::cout << "Joueur " << i << " : " << m_partie->joueurs[i]->points
                      << "." << std::endl;
        }
    }

    //return m_partie->gagnants_partie[0];
}

void Jeu::setupBt(QQmlApplicationEngine *engine)
{
    unoBt = engine->rootObjects()[0]->findChild<QObject*>("unoBt");
    if(!unoBt)
        qDebug()<<"unable to bind button unoBt";

    contreUnoBt = engine->rootObjects()[0]->findChild<QObject*>("contreUnoBt");
    if(!contreUnoBt)
        qDebug()<<"unable to bind button contreUnoBt";

    playCardBt = engine->rootObjects()[0]->findChild<QObject*>("drawCardBt");
    if(!playCardBt)
        qDebug()<<"unable to bind button playCardBt";

    drawCardBt = engine->rootObjects()[0]->findChild<QObject*>("playCardBt");
    if(!drawCardBt)
        qDebug()<<"unable to bind button drawCardBt";

    connect(unoBt,SIGNAL(unoBtPressed()),this,SLOT(unoBtPressed()));
    connect(contreUnoBt,SIGNAL(contreUnoBtPressed()),this,SLOT(contreUnoBtPressed()));
    // wtf les deux connect play et draw bug ???
    connect(playCardBt,SIGNAL(qplayCardBtPressed(int)),this,SLOT(playCardBtPressed(int)));
    connect(drawCardBt,SIGNAL(qdrawCardBtPressed()),this,SLOT(drawCardBtPressed()));
}

QString Jeu::curCardColor()
{
    return couleur_to_string2(m_partie->manche_courante->active->couleur);
}
int Jeu::curCardType()
{
    return m_partie->manche_courante->active->type;
}
int Jeu::curCardValue()
{
    return m_partie->manche_courante->active->valeur;
}

void Jeu::updateCurCard()
{
    emit curCardColorChanged();
    emit curCardTypeChanged();
    emit curCardValueChanged();
    qDebug()<<m_partie->manche_courante->active->couleur;
    qDebug()<<m_partie->manche_courante->active->type;
    qDebug()<<m_partie->manche_courante->active->valeur;
}

void Jeu::updateHand(int id_joueur)
{
    // parcour la main du joueur noyau pour la mettre dans hand correspondante
    // offset avec mon_numero ?
    hands[id_joueur].clear();
    for(unsigned int j = 0; j<m_partie->joueurs.at(id_joueur)->cmain.size();j++)
    {
        int t = m_partie->joueurs.at(id_joueur)->cmain.at(j)->type;
        QString c = couleur_to_string2(m_partie->joueurs.at(id_joueur)->cmain.at(j)->couleur);
        int v = m_partie->joueurs.at(id_joueur)->cmain.at(j)->valeur;
        hands[id_joueur].appendItem(t,c,v);
    }
}

int Jeu::waitForBtPressed()
{
    // exec retourne avec le code de exit (voir xBtPressed)
    return eventLoop.exec();
}

void Jeu::unoBtPressed()
{
    // evenement à trigger si on est en attente d'une input
    if(eventLoop.isRunning()){
        // some event
        // exit() donne un code retour specifique à exec() (voir waitForBtPressed)
        eventLoop.exit(BT_UNO);
    }
    qDebug()<<"boutton uno pressé";
}

void Jeu::contreUnoBtPressed()
{
    if(eventLoop.isRunning())
        eventLoop.exit(BT_CUNO);

    qDebug()<<"boutton contre uno pressé";
}

void Jeu::playCardBtPressed(int i)
{
    if(eventLoop.isRunning()){
        current_card_nb = i;
        eventLoop.exit(BT_PLAY);
    }

    qDebug()<<"boutton contre uno pressé";
}

void Jeu::drawCardBtPressed()
{
    if(eventLoop.isRunning())
        eventLoop.exit(BT_DRAW);

    qDebug()<<"boutton contre uno pressé";
}

QString Jeu::couleur_to_string2(Couleur c)
{
    QString nom_couleur;

    switch(c)
    {
    case ROUGE:
        nom_couleur = "r";
        break;

    case VERT:
        nom_couleur = "v";
        break;

    case BLEU:
        nom_couleur = "b";
        break;

    case JAUNE:
        nom_couleur = "j";
        break;

    case NOIR:
        nom_couleur = "n";
        break;
    default:
        nom_couleur = "x";
        break;
    }

    return nom_couleur;
}
