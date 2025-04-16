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

//iterativ
void inserare(Nod *&rad, int val) {
    if (rad == nullptr) {
        rad = makeNod(val);
        return;
    }

    Nod* curent = rad;
    Nod* parinte = nullptr;

    while (curent != nullptr) {
        parinte = curent;
        if (val < curent->data)
            curent = curent->stg;
        else if (val > curent->data)
            curent = curent->drt;
        else
            return;
    }

    if (val < parinte->data)
        parinte->stg = makeNod(val);
    else
        parinte->drt = makeNod(val);
}

// iterativ
bool search(Nod *&rad, int val) {
    while(rad) {
        if(rad->data == val) {
            return true;
        } else if(val < rad->data) {
            rad = rad->stg;
        } else if (val > rad->data) {
            rad = rad->drt;
        }
    }  
    return false; 
}

int nrCopii(Nod *rad) {
    int nr = 0;
    if(rad->stg) {
         nr++;
    }
    if(rad->drt) {
        nr++;
    }
    return nr;
}

void deleteNod(Nod *&rad, int val) {
    if (rad == nullptr) return;

    Nod* curent = rad;
    Nod* parinte = nullptr;

    while (curent && curent->data != val) {
        parinte = curent;
        if (val < curent->data)
            curent = curent->stg;
        else
            curent = curent->drt;
    }

    if (curent == nullptr) {
        cout << "Valoarea nu exista in arbore\n";
        return;
    }

    //3 cazuri (0/1/2)  
    int nr = nrCopii(curent);
    //caz 0 copii
    if (nr == 0) {
        if (parinte == nullptr) {
            deleteRoot(rad);
        } else if (parinte->stg == curent) {
            parinte->stg = nullptr;
            delete curent;
        } else if (parinte->drt == curent) {
            parinte->drt = nullptr;
            delete curent;
        }
        return;
    }

    //caz 1 copil
    if(nr == 1) {
        if(curent->stg) {
            if(parinte == nullptr) {
                rad = curent->stg;
                delete curent;
            } else {
                if(parinte->stg == curent) {
                    parinte->stg = curent->stg;
                    delete curent;
                } else if(parinte->drt == curent) {
                    parinte->drt = curent->stg;
                    delete curent;
                }
            }
        }
        if(curent->drt && curent->stg == nullptr) {
            if(parinte == nullptr) {
                rad = curent->drt;
                delete curent;
            } else {
                if(parinte->stg == curent) {
                    parinte->stg = curent->drt;
                    delete curent;
                } else if(parinte->drt == curent) {
                    parinte->drt = curent->drt;
                    delete curent;
                }
            }
        }

        return;
    }
    //caz 2 copii 
    if (nr == 2) {
        Nod* inlocuitor = removeGreatest(curent->stg);
        curent->data = inlocuitor->data;
        delete inlocuitor;
        return;
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