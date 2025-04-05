#include <iostream>
#include "lista_dubla_circulara.h"
using namespace std;

int main() {
    Nod* lista = nullptr;

    inserareInFata(lista, 3);
    inserareInFata(lista, 2);
    inserareInFata(lista, 1);

    inserareLaFinal(lista, 4);
    inserareLaFinal(lista, 5);

    cout << "Stanga -> Dreapta: ";
    afisareStangaDreapta(lista); // 1 <-> 2 <-> 3 <-> 4 <-> 5

    cout << "\nDreapta -> Stanga: ";
    afisareDreaptaStanga(lista); // 5 <-> 4 <-> 3 <-> 2 <-> 1

    stergere(lista, 3);
    cout << "\nDupa stergere(3): ";
    afisareStangaDreapta(lista); // 1 <-> 2 <-> 4 <-> 5

    stergeLista(lista);
    cout << "\nDupa stergere totala: ";
    afisareStangaDreapta(lista); // nullptr

    return 0;
}
