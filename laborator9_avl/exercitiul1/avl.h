#ifndef AVL_H
#define AVL_H

struct Nod {
    int data;
    Nod* stg;
    Nod* drt;
};

void afisarePreordine(Nod* p);
void afisareInordine(Nod* p);
void afisarePostordine(Nod* p);
Nod* makeNod(int val);
void inserare(Nod *&rad, int val);
bool search(Nod *&rad, int val);
void deleteNod(Nod *&rad, int val);
void deleteRoot(Nod *&rad);
Nod* removeGreatest(Nod*& r);

#endif 
