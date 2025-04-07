#include <iostream>
#include <cctype>
#include <cstdlib>
using namespace std;

#include "arbore.h"

static char car = 0;

//citire

static void eroare() {
    printf("Sirul de intrare este eronat!\n");
    printf("Apasati o tasta...");
    getchar();
    exit(1);
}

static char readchar() {
    char c;
    do {
        c = getchar();
    } while (c == ' ');
    return c;
}

static char citesteNume() {
    char c;
    if (!isalpha(car)) {
        eroare();
    }
    c = car;
    car = readchar();
    return c;
}

static Nod* citesteArbore() {
    Nod* rad;
    if (car == '-') {
        rad = nullptr;
        car = readchar();
    } else {
        rad = new Nod;
        rad->data = citesteNume();
        if (car != '(') {
            rad->stg = nullptr;
            rad->drt = nullptr;
        } else {
            car = readchar();
            rad->stg = citesteArbore();
            if (car != ',') {
                rad->drt = nullptr;
            } else {
                car = readchar();
                rad->drt = citesteArbore();
            }
            if (car != ')') {
                eroare();
            }
            car = readchar();
        }
    }
    return rad;
}

Nod* creareArbore() {
    printf("Exemplu: A(B(-,C),D(E(F,-),G(H,-)))\n");
    printf("Introduceti arborele: ");
    car = readchar();
    return citesteArbore();
}

// functii 

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
    if (!p) {
        return 0;
    }

    int ad_stg = adancime(p->stg);
    int ad_drt = adancime(p->drt);

    return 1 + max(ad_stg, ad_drt);
}

int numarNoduri(Nod* p) {
    if (!p) {
        return 0;
    }

    return 1 + numarNoduri(p->stg) + numarNoduri(p->drt);
}

int numarFrunze(Nod* p) {
    if (!p) {
        return 0;
    }

    if (!p->stg && !p->drt) {
        return 1;
    }

    return numarFrunze(p->stg) + numarFrunze(p->drt);
}

void distrugeArbore(Nod* p) {
    if (p) {
        distrugeArbore(p->stg);
        distrugeArbore(p->drt);
        delete p;
    }
}

// ==== FUNCTIE PUNCT F) ====

char max_subarbore(Nod* p) {
    if (p == nullptr) {
        return 0;
    }

    char max_st = (p->stg != nullptr) ? max(p->stg->data, max_subarbore(p->stg)) : 0;
    char max_dr = (p->drt != nullptr) ? max(p->drt->data, max_subarbore(p->drt)) : 0;

    return max(max_st, max_dr);
}

void afisare_f(Nod* p) {
    if (p == nullptr) {
        return;
    }

    afisare_f(p->stg);
    afisare_f(p->drt);

    if (p->data > max_subarbore(p)) {
        cout << p->data << endl;
    }
}

char minim_subarbore(Nod* p) {
	exit(1);
}
void afisare_g(Nod* p) {
	return ;
}