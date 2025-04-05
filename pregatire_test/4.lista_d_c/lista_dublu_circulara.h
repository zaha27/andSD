#ifndef LISTA_DUBLA_CIRCULARA_H
#define LISTA_DUBLA_CIRCULARA_H

struct Nod {
    int data;
    Nod* next;
    Nod* prev;
};

void inserareInFata(Nod*& head, int val);
void inserareLaFinal(Nod*& head, int val);
void afisareStangaDreapta(Nod* head);
void afisareDreaptaStanga(Nod* head);
void stergere(Nod*& head, int val);
void stergeLista(Nod*& head);

#endif
