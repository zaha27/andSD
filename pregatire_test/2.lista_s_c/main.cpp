#include <iostream>
#include "lista_circulara.h"

using namespace std;

int main() {
    Nod* lista = nullptr;

    inserareLaFinal(lista, 10);
    inserareLaFinal(lista, 20);
    inserareInFata(lista, 5);
    inserareInFata(lista, 1);

    cout << "Lista circulara: ";
    afisare(lista);

    stergeLista(lista);
    cout << "Dupa eliberare: ";
    afisare(lista);

    return 0;
}
