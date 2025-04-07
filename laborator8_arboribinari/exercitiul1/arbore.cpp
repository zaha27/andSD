#include <iostream>
using namespace std;
#include "arbore.h"

Nod* creareArbore() {
    char ch;
    cin >> ch;
    if (ch == '-') return nullptr;

    Nod* p = new Nod;
    p->data = ch;
    p->stg = creareArbore();
    p->drt = creareArbore();
    return p;
}

void afisarePreordine(Nod* p) {
    if (p) {
        cout << p->data << " ";
        afisarePreordine(p->stg);
        afisarePreordine(p->drt);
    }
}

void afisareInordine(Nod* p) {
    if (p) {
        afisareInordine(p->stg);
        cout << p->data << " ";
        afisareInordine(p->drt);
    }
}

void afisarePostordine(Nod* p) {
    if (p) {
        afisarePostordine(p->stg);
        afisarePostordine(p->drt);
        cout << p->data << " ";
    }
}

int adancime(Nod* p) {
    if (!p) return 0;
    int ad_stg = adancime(p->stg);
    int ad_drt = adancime(p->drt);
    return 1 + max(ad_stg, ad_drt);
}

int numarNoduri(Nod* p) {
    if (!p) return 0;
    return 1 + numarNoduri(p->stg) + numarNoduri(p->drt);
}

int numarFrunze(Nod* p) {
    if (!p) return 0;
    if (!p->stg && !p->drt) return 1;
    return numarFrunze(p->stg) + numarFrunze(p->drt);
}

void distrugeArbore(Nod* p) {
    if (p) {
        distrugeArbore(p->stg);
        distrugeArbore(p->drt);
        delete p;
    }
}
