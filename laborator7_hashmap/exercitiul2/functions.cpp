#include <iostream>
#include "header.h"

int my_hash_one(int key) {
    return key % M;
}

int my_hash_two(char *key) {
    h = 5381;
    while (c = *key++)
        h += (h << 5) + c;
    return h;
}

int my_hash_three(int key) {

    double A = 0.6180339887; 
    double val = key * A;
    double fract = val - (int)val; 
    return (int)(M * fract);
}

void init(Nod *HT[]) {
    for(int i = 0; i < M; ++i) {
        HT[i] = nullptr;
    }
}

void insert(Nod *HT[], char *cuv) {
    int poz = my_hash(cuv);
    char* duplicate = strdup(cuv);
    Nod* p = new Nod;
    p->cheie = duplicate;
    p->urm = HT[poz];
    HT[poz] = p;
}


void sterge(Nod* HT[], char* cuv) {
    int h = my_hash(cuv);
    Nod* p = HT[h], *prev = nullptr;
    while (p) {
        if (strcmp(p->cheie, cuv) == 0) {
            if (prev) prev->urm = p->urm;
            else HT[h] = p->urm;
            free(p->cheie);
            delete p;
            return;
        }
        prev = p;
        p = p->urm;
    }
}

bool cautare(Nod* HT[], char* cuv) {
    int h = my_hash(cuv);
    for (Nod* p = HT[h]; p; p = p->urm)
        if (strcmp(p->cheie, cuv) == 0)
            return true;
    return false;
}

void afisare(Nod* HT[]) {
    for (int i = 0; i < M; i++) {
        if (HT[i]) {
            cout << "Slot " << i << ": ";
            for (Nod* p = HT[i]; p; p = p->urm)
                cout << p->cheie << " -> ";
            cout << "nullptr\n";
        }
    }
}

void cluster_functions(Nod* HT[], int NUMAR) {
    int x[NUMAR] = {0};
    int N = 0;      

    for (int i = 0; i < M; ++i) {
        Nod* p = HT[i];
        while (p) {
            x[i]++;
            N++;
            p = p->urm;
        }
    }

    if (N == 0) {
        cout << "Tabela este goala.\n";
        return;
    }

    double alpha = (double)N / NUMAR;
    double sum_xi2 = 0;

    for (int i = 0; i < M; ++i)
        sum_xi2 += x[i] * x[i];

    double C = sum_xi2 / (N - alpha);

    cout << "Gradul de clusterizare: " << C << "\n";
}


void afisareTabel(Nod *HT[]) {
    cout << "------------------";
    cout << "----f1----f2----f3";
    for(i = 0 ; i < 3; i++) {
        
    }
}