#include "types.h"

/// Paramètre à utiliser pour la génération pseudo-aléatoire des nombres.
static uint32_t next = 1;

int my_rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65536) % 32768;
}

void my_srand(unsigned int seed)
{
    next = seed;
}

std::ostream &operator << (std::ostream &out, const TypeMessage t)
{
    /// Transforme le nom du TypeMessage en chaine de charactère.
    switch(t)
    {
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
            out << "TYPE_MESSAGE_INCONNU";
            break;
    }

    return out;
}

