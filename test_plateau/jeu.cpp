#include "jeu.h"
#include <QDebug>

Jeu::Jeu(QObject *parent) :
    QObject(parent)
{
    m_partie = new Partie(MANCHE_UNIQUE,2);
    m_partie->set_seed(42);
    m_partie->nouvelle_manche();
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
        qDebug()<<"joueur "<<i;
        hands[i].clear();
        for(unsigned int j = 0; j<m_partie->joueurs.at(i).cmain.size();j++)
        {
            qDebug()<<"carte "<<j;
            int t = m_partie->joueurs.at(i).cmain.at(j)->type;
            QString c = couleur_to_string2(m_partie->joueurs.at(i).cmain.at(j)->couleur);
            int v = m_partie->joueurs.at(i).cmain.at(j)->valeur;
            qDebug()<<t<<c<<v;
            hands[i].appendItem(t,c,v);
        }
    }
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
