#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "jeu.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //Jeu jeu;


    //QQmlContext *ctx=engine.rootContext();
    //ctx->setContextProperty("game",&jeu);
    qmlRegisterType<Jeu>("game.backend", 1,0,"BackEnd");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

#if 0
#include <iostream>
#include"partie.h"
#include"pioche.h"
#include"carte.h"
#include"joueur.h"
#include "joueuria.h"

int main()
{
   Partie jeu(MANCHE_UNIQUE, 2);

   std::vector<Joueur*> gagnants_partie;
   Joueur *gagnant_manche;
   int joueur_suivant;



   jeu.set_seed(42);


   while(!jeu.partie_finie(&gagnants_partie))
   {
       Manche *m = jeu.nouvelle_manche();

       jeu.joueurs[0].afficher_main();
       jeu.joueurs[1].afficher_main();

       std::cout << "Première carte : " << m->active << std::endl;

       while(!jeu.manche_finie(&gagnant_manche))
       {
            joueur_suivant = m->joueur_suivant();

            // Si joueur_suivant c'est moi, alors interaction IHM
            // Si c'est un autre joueur, attente de son action
            jeu.get_joueur(joueur_suivant)->action_par_defaut();

            /*if(m->couleur_active == NOIR)
            {
                jeu.get_joueur(joueur_suivant)->choisir_couleur_defaut();
            }*/

            std::cerr << std::endl;



            if(m->tours.back().action == JOUE_CARTE
                    && m->tours.back().carte->couleur == NOIR)
            {
                jeu.get_joueur(joueur_suivant)->choisir_couleur_defaut();
            }


       }
       std::cout << "gagnant manche : " << gagnant_manche->num_joueur << std::endl;
   }

   std::cout << jeu.get_joueur(0)->points << "\t" << jeu.get_joueur(1)->points << "\t"
             /*<< jeu.get_joueur(2)->points << "\t" << jeu.get_joueur(3)->points << "\t"*/ << std::endl;

   std::cout << "Gagnant manche : " << gagnant_manche->num_joueur << std::endl;
   std::cout << "Gagnant partie : " << gagnants_partie[0]->num_joueur << std::endl;

   return 0;
}

#endif
