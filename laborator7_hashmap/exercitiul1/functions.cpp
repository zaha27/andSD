#include <iostream>
#include "header.h"

int my_hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i]; i++)
        sum += key[i];
    return sum % M;
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