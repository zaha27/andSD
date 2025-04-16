#include <iostream>
#include "bst.h"

using namespace std;

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

Nod* makeNod(int val) {
    Nod *x = new Nod;
    x->data = val;
    x->stg = nullptr;
    x->drt = nullptr;
    return x;
}

void inserare(Nod *&rad, int val) {
    if(rad == nullptr) {
        rad = makeNod(val);
    } else if(val < rad->data) {
        inserare(rad->stg, val);
    } else {
        inserare(rad->drt, val);
    }
}

bool search(Nod *&rad, int val) {
    if(rad == nullptr) {
        return false;
    } else if(val < rad->data) {
        return search(rad->stg, val);
    } else if(val > rad->data) {
        return search(rad->drt, val);
    } else {
        return true;
}

}
void deleteNod(Nod *&rad, int val) {
    if(rad == nullptr) {
        cout<<"Eroare: Valoarea "<< val <<"nu este in arbore";
    } else if(val < rad->data) {
        deleteNod(rad->stg, val);
    } else if(val > rad->data) {
        deleteNod(rad->drt, val);
    } else {
        deleteRoot(rad);
    }
}

void deleteRoot(Nod *&rad) {
    Nod* p = rad;
    if( rad->stg==0) 
        rad = rad->drt;
    else if( rad->drt==0) 
        rad = rad->stg;
    else {
        rad = removeGreatest (rad->stg);
        rad->stg = p->stg;
        rad->drt = p->drt;
    }
    delete p;
}

Nod* removeGreatest(Nod*& r) {
    Nod* p;
    if(r->drt == nullptr) {
        p = r;
        r = r->stg;
        return p;
    } else {
        return removeGreatest(r->drt);
    }
}