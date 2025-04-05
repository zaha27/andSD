#include <iostream>
#include "lista.h"

using namespace std;

int main() {

    cout << "\n";
    cout << "\n";

    Nod* lista = nullptr;

    inserareInFata(lista, 10);
    inserareInFata(lista, 5);
    inserareLaFinal(lista, 15);
    inserareLaFinal(lista, 20);

    cout << "Lista dupa inserari: ";
    afisare(lista); // 5 10 15 20


    cout << "\n";

    stergere(lista, 10);
    cout << "Lista dupa stergerea lui 10: ";
    afisare(lista); // 5 15 20

    cout << "\n";

    stergeLista(lista);
    cout << "Lista dupa eliberare: ";
    afisare(lista); // nimic


    cout << "\n";
    cout << "\n";
    cout << "\n";

    return 0;
}
