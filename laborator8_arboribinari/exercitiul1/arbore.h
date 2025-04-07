#ifndef ARBORE_H
#define ARBORE_H

struct Nod {
    char data;
    Nod* stg;
    Nod* drt;
};

Nod* creareArbore();

void afisarePreordine(Nod* rad);
void afisareInordine(Nod* rad);
void afisarePostordine(Nod* rad);

int adancime(Nod* rad);
int numarNoduri(Nod* rad);
int numarFrunze(Nod* rad);
void afisare_f(Nod* rad);


void distrugeArbore(Nod* rad);

#endif
