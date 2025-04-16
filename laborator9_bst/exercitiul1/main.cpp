#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    Nod* rad = nullptr;
    int val;

    cout << "valori:";
    while (val != 0) {
        cin >> val;
        inserare(rad, val);
    }

    cout << "inordine: ";
    afisareInordine(rad); cout << "\n";

    cout << "preordine: ";
    afisarePreordine(rad); cout << "\n";

    cout << "postordine: ";
    afisarePostordine(rad); cout << "\n";

    cout << "val(de cautat) = ";
    cin >> val;
    (search(rad, val))? cout << "true" : cout << "false";

    cout << "val(de sters) = ";
    cin >> val;
    deleteNod(rad, val);

    cout << "inordine dupa delete";
    afisareInordine(rad); cout << "\n";

    return 0;
}
