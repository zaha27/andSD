#include <iostream>
using namespace std;

#include "arbore.h"

int main() {
    // Exemplu: A(B(-,-),C(D(-,-),E(-,-)))
    // Input:   A B - - C D - - E - -

    cout << "introdu arborele" << endl;
    Nod* rad = creareArbore();

    cout << "\ninordine: ";
    afisareInordine(rad);
    cout << "\npostordine: ";
    afisarePostordine(rad);

    cout << "\n\nadancime: " << adancime(rad);
    cout << "\nnumarul de noduri: " << numarNoduri(rad);
    cout << "\nnumarul de frunze: " << numarFrunze(rad) << endl;

    cout << "\nnodurile care au valoarea mai mare decat toate valorile din subarbori:\n";
    afisare_f(rad);

    distrugeArbore(rad);
    return 0;
}
