#ifndef LISTA_H
#define LISTA_H

struct Nod {
    int data;
    Nod* next;
};

void inserareInFata(Nod*& cap, int val);
void inserareLaFinal(Nod*& cap, int val);
void stergere(Nod*& cap, int val);
void afisare(Nod* cap);
void stergeLista(Nod*& cap);

#endif
