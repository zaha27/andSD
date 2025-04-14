#ifndef ARBORE_H
#define ARBORE_H

struct Nod {
    char data;
    Nod* stg;
    Nod* drt;
};

Nod* creareArbore();

// Parcurgeri
void afisarePreordine(Nod* p);
void afisareInordine(Nod* p);
void afisarePostordine(Nod* p);

// Operatii pe arbore
int adancime(Nod* p);
int numarNoduri(Nod* p);
int numarFrunze(Nod* p);

// Eliberare memorie
void distrugeArbore(Nod* p);

// Punctul f) din laborator
char max_subarbore(Nod* p);
void afisare_f(Nod* p);

// Punctul g) din laborator
char minim_subarbore(Nod* p);
void afisare_g(Nod* p);

#endif
