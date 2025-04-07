#include <iostream>
using namespace std;

#include "arbore.h"

int main() {
    cout << "Introduceti arborele in forma A(B(-,C),D(E(F,-),G(H,-))):\n";
    Nod* rad = creareArbore();

    cout << "\nParcurgere inordine: ";
    afisareInordine(rad);

    cout << "\nParcurgere postordine: ";
    afisarePostordine(rad);

    cout << "\nParcurgere preordine: ";
    afisarePreordine(rad);

    cout << "\n\nAdancime: " << adancime(rad);
    cout << "\nNumar noduri: " << numarNoduri(rad);
    cout << "\nNumar frunze: " << numarFrunze(rad) << endl;

    cout << "\nNodurile care au valoarea mai mare decat toate valorile din subarbori:\n";
    afisare_f(rad);

	cout <<

    distrugeArbore(rad);
    return 0;
}
