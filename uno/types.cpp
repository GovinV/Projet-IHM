#include "types.h"

std::ostream &operator << (std::ostream &out, const TypeMessage t)
{
    switch (t) {
    case DEBUT_PARTIE:
        out << "DEBUT_PARTIE";
        break;
    case FIN_PARTIE:
        out << "FIN_PARTIE";
        break;
    case DEBUT_MANCHE:
        out << "DEBUT_MANCHE";
        break;
    case FIN_MANCHE:
        out << "FIN_MANCHE";
        break;
    case JOUEUR_ACTION:
        out << "JOUEUR_ACTION";
        break;
    case JOUEUR_CHOIX_COULEUR:
        out << "JOUEUR_CHOIX_COULEUR";
        break;
    default:
        break;
    }
    return out;
}
