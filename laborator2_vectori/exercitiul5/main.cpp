#include <iostream>
#include "cb.h"

using namespace std;

int main() {
    int **a, n, x;
    cout << "Introdu un numar natural: ";
    cin >> n;
    if (n < 0) {
        cout << "Nu ai introdus un numar natural! \n";
        return 0;
    }
    cout << "Introdu numarul pe care vrei sa-l cauti: ";
    cin >> x;
    a = citire_matrice(n);

    cb_matrice(a, n, x);

    dealocare_matrice(a, n);
    return 0;
}