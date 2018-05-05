#include "jeu.h"
#include <QDebug>

#define BT_UNO 1
#define BT_CUNO 2
#define BT_PLAY 3
#define BT_DRAW 4
#define BT_COLOR 5

Jeu::Jeu(QObject *parent) :
    QObject(parent)
{
    qDebug()<<"init";
    qsrand(QTime::currentTime().msec());
}

void Jeu::start()
{

    m_partie = new Partie(MANCHE_UNIQUE,4);
    int myseed = rand() %100;
    m_partie->set_seed(myseed);
    qDebug()<<"myseed:"<< myseed;
    m_partie->nouvelle_manche(0);

    //hands[0].appendItem(TYPE_NB,"v",5);
    //qDebug()<<"hello";
    init_deck();
    //gameLoop();
    //QtConcurrent::run(this, &Jeu::gameLoop,&(hands[0]));

    mon_numero=0;

    Carte *c = m_partie->manche_courante->active;
    emit curCardChange(c->type,couleur_to_string2(c->couleur),c->valeur);

    gameStep();

}

void Jeu::gameStep()
{
    message = m_partie->update_and_get_next_message();
    qDebug() << "step 1";
    if(message != NULL && message->type != FIN_PARTIE)
    {
        qDebug() << "step 2";
        switch(message->type)
        {
            case JOUEUR_ACTION:
                qDebug() << "step 3";
                if(message->num_joueur == mon_numero)
                {
                    myturn=true;
                    emit myTurn();
                }
                else
                    iaLoop();
                updateHand(message->num_joueur);
                break;

            case JOUEUR_CHOIX_COULEUR:
                if(message->num_joueur == mon_numero)
                {
                    myturn=true;
                    emit selectColor();
                }
                else
                {
                     changeColor(couleur_to_string2(m_partie->joueurs[message->num_joueur]->choisir_couleur_defaut()));
                     gameStep();
                }
                break;

            case DEBUT_PARTIE:
                std::cout << "\nLa partie commence !" << std::endl;
                gameStep();
                break;

            case DEBUT_MANCHE:
                std::cout << "\nUne manche vient de commencer !" << std::endl;
                std::cout << "Carte sur la table : "
                      << m_partie->manche_courante->active << "\n" << std::endl;
                gameStep();
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
                gameStep();
                break;
            default:
                gameStep();
                break;
        }
    }
    else if(message != NULL && message->type != FIN_PARTIE)
    {
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
    }
}


void Jeu::playerLoop()
{
    qDebug() << "vraiment ?!";
    //m_partie->joueurs[mon_numero]->afficher_main();
    ///std::cout << "Carte sur la table : "
    ///       << m_partie->manche_courante->active << "\n" << std::endl;
    std::cout << "Choix de l'action : ";
    ///std::cin >> action;
    ///switch(action)
    bool fin_tour = false;
    switch(action)
    {
        // on récupère le code boutton et on agis en fonction
        case BT_PLAY:///'p'
            ///std::cout << "Saisir la carte à jouer : ";
            ///std::cin >> saisie_nb;
            ///std::cout << std::endl;
            if(m_partie->joueurs[mon_numero]->jouer(current_card_nb))
            {
                playCard(current_card_nb,mon_numero);
                Carte *c = m_partie->manche_courante->active;
                emit playCardOk();
                emit curCardChange(c->type,couleur_to_string2(c->couleur),c->valeur);
                //updateHand(mon_numero);
                myturn=false;
                fin_tour = true;
                emit waitForIA();
            }
            break;
        case BT_DRAW:
            ///std::cout << std::endl;
            ///m_partie->joueurs[mon_numero]->piocher();

            //piocher est déjà activer par un elem QML, mais normalement
            //elle devrait être trigger ici (ne marche pas a cause du bug connect)
            drawCard(mon_numero);
            //updateHand(mon_numero);
            emit playCardOk();
            myturn=false;
            fin_tour = true;
            break;
        case BT_UNO:
            m_partie->joueurs[mon_numero]->appuie_uno();
            break;
        case BT_COLOR:
            m_partie->joueurs[mon_numero]->choisir_couleur(static_cast<Couleur>(new_color));
            emit playCardOk();
            myturn=false;
            fin_tour = true;
            break;
        case BT_CUNO:
            /** std::cout << "Saisir le joueur : " << std::endl;
            std::cin >> saisie_nb;
            m_partie->joueurs[saisie_nb]->appuie_contre_uno();*/
            break;
        default:
            break;
    }
    if(fin_tour)
    {
        gameStep();
    }
}

void Jeu::iaLoop()
{

    m_partie->joueurs[message->num_joueur]->action_par_defaut();
    Carte *c = m_partie->manche_courante->active;
    emit curCardChange(c->type,couleur_to_string2(c->couleur),c->valeur);

    updateHand(message->num_joueur);

    //QThread::msleep(1000);
    //gameStep();
    emit waitForIA();
}

void Jeu::nextStepIA()
{
    gameStep();
}

void Jeu::test()
{
    qDebug()<<"exit value:";
}

void Jeu::init_deck()
{

    for(unsigned int i = 0;i< m_partie->joueurs.size();i++)
    {
        updateHand(i);
    }
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

void Jeu::unoBtPressed()
{
    if(myturn)
    {
        action=BT_UNO;
        waiting=false;
        qDebug()<<"boutton uno pressé";
        playerLoop();
    }
}

void Jeu::contreUnoBtPressed()
{
    if(myturn)
    {
        action=BT_CUNO;
        waiting=false;
        qDebug()<<"boutton contre uno pressé";
        playerLoop();
    }
}

void Jeu::playCardBtPressed(int i)
{
    qDebug() <<"oui non ?";
    if(myturn)
    {
        current_card_nb = i;
        action=BT_PLAY;
        waiting=false;
        qDebug()<<"essaye de jouer une carte";
        playerLoop();
    }
}

void Jeu::playChangeColor(int cl)
{
    if(myturn)
    {
        action=BT_COLOR;
        waiting=false;
        new_color=cl;
        qDebug()<<"playChangeColor";
        playerLoop();
    }
}

void Jeu::drawCardBtPressed()
{
    //addCard(0,0,"r",8);
    qDebug() << "drawCardBtPressed";
    if(myturn)
    {
        action=BT_DRAW;
        waiting=false;
        qDebug()<<"tire une carte";
        playerLoop();
    }
}

// i indice du joueur receveur
void Jeu::drawCard(int id_joueur)
{
    m_partie->joueurs[id_joueur]->piocher();
    updateHand(id_joueur);
}

// i indice de la carte
void Jeu::playCard(int index, int joueur)
{
    HandItem c = hands[joueur].getItem(index);
    emit curCardChange(c.type,c.color,c.value);
    hands[joueur].removeItem(index);
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
