#include "cartenombre.h"

CarteNombre::CarteNombre(int n, int c)
{
    numero=n;
    couleur=c;

    type="Carte nombre ";

    std::cout << "Carte cree de couleur " << couleur << " et de nombre " << numero << "\n";
}
