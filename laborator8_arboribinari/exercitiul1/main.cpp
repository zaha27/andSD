#include <iostream>
using namespace std;
#include "arbore.h"

int main() {
    cout << "Introdu arborele in forma cu paranteze (- pentru NULL):\n";
    Nod* rad = creareArbore();

    cout << "\nParcurgere PREORDINE: ";
    afisarePreordine(rad);

    cout << "\nParcurgere INORDINE: ";
    afisareInordine(rad);

    cout << "\nParcurgere POSTORDINE: ";
    afisarePostordine(rad);

    cout << "\n\nAdancime: " << adancime(rad);
    cout << "\nNumar noduri: " << numarNoduri(rad);
    cout << "\nNumar frunze: " << numarFrunze(rad) << "\n";

    distrugeArbore(rad);
    return 0;
}
