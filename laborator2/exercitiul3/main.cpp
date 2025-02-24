#include <iostream>
#include "rotire90.h"

using namespace std;

int main() {
    int **a, n;
    cout << "Introdu un numar natural: ";
    cin >> n;
    if (n < 0) {
        cout << "Nu ai introdus un numar natural! \n";
        return 0;
    }

    a = citire_matrice(n);

    rotire_matrice(a, n);
    afisare_matrice_clasic(a, n);
    
    dealocare_matrice(a, n);
    return 0;
}