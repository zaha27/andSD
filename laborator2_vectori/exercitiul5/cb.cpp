#include <iostream>
#include "cb.h"

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

void dealocare_matrice(int **a, int n) {  
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

int cb_linie(int *v, int st, int dr, int x) {
    while (st <= dr) {
        int m = st + (dr - st) / 2;
        if (v[m] == x) {
            return m;
        }
        if (v[m] < x) {
            st = m + 1;
        }
        else {
            dr = m - 1;
        }
    }
    return -1;
}

void cb_matrice(int **a, int n, int x) {
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp = cb_linie(a[i], 0, n, x);
        if(tmp != -1) {    //daca a fost gasit
            cout << "pozitiile sunt: " << i << " " << tmp;
            return ;
        }
    }
    cout << "x nu a fost gasit !!!";
    return ;
}