#include <iostream>
#include "rotire90.h"

using namespace std;

int **alocare_matrice(int n) {
    int **a;
    a = new int*[n];
    
    for(int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }
    return a;
}

int **citire_matrice(int n) {
    int **a;
    a = alocare_matrice(n);

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    return a;
}

void rotire_matrice(int **a, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            swap(a[i][j], a[j][i]);
    }
}

void afisare_matrice_clasic(int **a, int n) {
    for(int i = 0; i < n; ++i){
        cout << '\n';
        for(int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
    }
    cout << '\n';
}

void dealocare_matrice(int **a, int n) {  
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}