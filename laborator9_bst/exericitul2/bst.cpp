#include <iostream>
#include "bst.h"

using namespace std;

// Parcurgeri
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

// Creare nod nou
Nod* makeNod(int val) {
    Nod* x = new Nod;
    x->data = val;
    x->stg = nullptr;
    x->drt = nullptr;
    return x;
}

// Inserare iterativa
void inserare(Nod*& rad, int val) {
    if (rad == nullptr) {
        rad = makeNod(val);
        return;
    }

    Nod* curent = rad;
    Nod* parinte = nullptr;

    while (curent != nullptr) {
        parinte = curent;
        if (val < curent->data) {
            curent = curent->stg;
        } else if (val > curent->data) {
            curent = curent->drt;
        } else {
            return; // valoare deja existenta
        }
    }

    if (val < parinte->data) {
        parinte->stg = makeNod(val);
    } else {
        parinte->drt = makeNod(val);
    }
}

// Cautare iterativa
bool search(Nod* rad, int val) {
    while (rad) {
        if (rad->data == val) {
            return true;
        } else if (val < rad->data) {
            rad = rad->stg;
        } else {
            rad = rad->drt;
        }
    }
    return false;
}

// Returneaza numarul de copii (0, 1 sau 2)
int nrCopii(Nod* rad) {
    int nr = 0;
    if (rad->stg) {
        nr++;
    }
    if (rad->drt) {
        nr++;
    }
    return nr;
}

// Sterge radacina
void deleteRoot(Nod*& rad) {
    Nod* p = rad;

    if (rad->stg == nullptr) {
        rad = rad->drt;
    } else if (rad->drt == nullptr) {
        rad = rad->stg;
    } else {
        Nod* inlocuitor = removeGreatest(rad->stg);
        inlocuitor->stg = rad->stg;
        inlocuitor->drt = rad->drt;
        rad = inlocuitor;
    }

    delete p;
}

// Functie auxiliara pentru stergerea nodului maxim dintr-un subarbore
Nod* removeGreatest(Nod*& r) {
    if (r->drt == nullptr) {
        Nod* p = r;
        r = r->stg;
        return p;
    } else {
        return removeGreatest(r->drt);
    }
}

// Stergere nod cu valoare data
void deleteNod(Nod*& rad, int val) {
    if (rad == nullptr) {
        return;
    }

    Nod* curent = rad;
    Nod* parinte = nullptr;

    while (curent && curent->data != val) {
        parinte = curent;
        if (val < curent->data) {
            curent = curent->stg;
        } else {
            curent = curent->drt;
        }
    }

    if (curent == nullptr) {
        cout << "Valoarea nu exista in arbore\n";
        return;
    }

    int nr = nrCopii(curent);

    // Caz 0 copii
    if (nr == 0) {
        if (parinte == nullptr) {
            deleteRoot(rad);
        } else if (parinte->stg == curent) {
            parinte->stg = nullptr;
            delete curent;
        } else {
            parinte->drt = nullptr;
            delete curent;
        }
        return;
    }

    // Caz 1 copil
    if (nr == 1) {
        Nod* copil = (curent->stg) ? curent->stg : curent->drt;

        if (parinte == nullptr) {
            rad = copil;
        } else if (parinte->stg == curent) {
            parinte->stg = copil;
        } else {
            parinte->drt = copil;
        }

        delete curent;
        return;
    }

    // Caz 2 copii
    if (nr == 2) {
        Nod* inlocuitor = removeGreatest(curent->stg);
        curent->data = inlocuitor->data;
        delete inlocuitor;
        return;
    }
}
