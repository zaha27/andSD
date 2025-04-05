#ifndef LISTA_CIRCULARA_H
#define LISTA_CIRCULARA_H

struct Nod {
    int data;
    Nod* next;
};

// cap este un pointer la ultimul nod din listă
void inserareInFata(Nod*& cap, int val);
void inserareLaFinal(Nod*& cap, int val);
void afisare(Nod* cap);
void stergeLista(Nod*& cap);

#endif
