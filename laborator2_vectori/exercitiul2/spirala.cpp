#include <iostream>
#include "spirala.h"

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

void afisare_matrice_clasic(int **a, int n) {
    for(int i = 0; i < n; ++i){
        cout << '\n';
        for(int j = 0; j < n; ++j) {
            cout << a[i][j] << ' ';
        }
    }
    cout << '\n';
}

void afisare_matrice_spirala(int **a, int n) {
    int k = 0;
    while (k < (n + 1) / 2) {
        for(int i = k ; i < n - k; ++i) {
            cout << a[k][i] << ' ';
        }
        for(int i = k; i < n - k - 1; ++i) {
            cout << a[i][n - k - 1] << ' ';
        }
        for(int i = n - k - 1; i > k; --i) {
            cout << a[n - k - 1][i] << ' ';
        }
        for(int i = n - k - 1; i > k; --i) {
            cout << a[i][k] << ' ';
        }
        k++;
    }
    cout << '\n';    
}

void dealocare_matrice(int **a, int n) {  
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}