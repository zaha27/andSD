#include <iostream>
#include "smax.h"

using namespace std;

int *alocare_vector(int n) {
    return new int[n];
}

void citire_vector(int *v, int n) {
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

void afisare_vector(int *v, int n) {
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }
    cout << '\n';
}

void dealocare_vector(int *v) {
    delete[] v;
}

int sum_portiune(int *v, int i, int j) {
    int sum = 0;
    for(int k = i; k < j; k++) {
            sum += v[k];
    }
    return sum;
}

int smax_optim(int *v, int n) {
    //optim 
    //cu un singur for
}

int smax_clasic(int *v, int n) {
    int i, j, sum, maxi = v[1] + v[2], indexi, indexj;
    for(int i = 0; i < n; i++) {
        sum = 0;
        j = n - 1;
        while (i < j) {
            sum = sum_portiune(v, i, j);
            if(sum > maxi) {
                maxi = sum;
                indexi = i;
                indexj = j;
            }
            j--;
        }
    }
    cout <<"index i: ";
    cout << indexi <<'\n';
    cout <<"index j: ";
    cout << indexj;
    return maxi;
}


