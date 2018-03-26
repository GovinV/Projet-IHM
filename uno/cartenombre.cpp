#include "cartenombre.h"

CarteNombre::CarteNombre(int n, int c)
{
    couleur=c;
    numero=n;
    std::cout << "Carte cree de couleur " << couleur << " et de nombre " << numero << "\n";
}
