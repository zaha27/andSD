#include <iostream>
#include "spirala.h"

using namespace std;

int main() {
    int **a, n;
    cout << "Introdu un numar impar : ";
    cin >> n;
    if (!(n % 2)) {
        cout << "Nu ai introdus un numar impar! \n";
        return 0;
    }

    a = citire_matrice(n);
    afisare_matrice_clasic(a, n);
    afisare_matrice_spirala(a, n);

    dealocare_matrice(a, n);
    return 0;
}