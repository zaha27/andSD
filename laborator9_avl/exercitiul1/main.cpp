#include <iostream>
#include "avl.h"

using namespace std;

int main() {
    cout << "Introduceti arborele in forma A(B(-,C),D(E(F,-),G(H,-))):\n";
    Nod* rad = creareArbore();

    distrugeArbore(rad);
    return 0;
}
