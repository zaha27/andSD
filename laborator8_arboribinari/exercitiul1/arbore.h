#ifndef ARBORE_H
#define ARBORE_H

struct Nod {
    char data;
    Nod* stg;
    Nod* drt;
};

// Creare arbore dintr-o intrare în formă cu paranteze
Nod* creareArbore();

// Parcurgeri
void afisarePreordine(Nod* rad);
void afisareInordine(Nod* rad);
void afisarePostordine(Nod* rad);

// Operații
int adancime(Nod* rad);
int numarNoduri(Nod* rad);
int numarFrunze(Nod* rad);

// Dezalocare memorie
void distrugeArbore(Nod* rad);

#endif
