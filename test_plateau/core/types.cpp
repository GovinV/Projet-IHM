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

static unsigned long int next = 1;

int my_rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

void my_srand(unsigned int seed)
{
    next = seed;
}
