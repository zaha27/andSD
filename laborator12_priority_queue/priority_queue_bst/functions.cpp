#include "header.h"
#include <iostream>
using namespace std;

void insert(Nod*& rad, int val) {
    if (rad == nullptr) {
        rad = new Nod{val, nullptr, nullptr};
    } else if (val < rad->data) {
        insert(rad->stg, val);
    } else {
        insert(rad->drt, val);
    }
}

int topMax(Nod* rad) {

    if(rad == nullptr) {
        cout << "arbore gol";
        exit(1);
    }

    Nod *p = rad;
    while (p->drt) {
        p = p->drt;
    }
    return p->data;    
}

int extractMax(Nod*& rad) {
    if (rad == nullptr) {
        cout << "arbore gol";
        exit(1);
    }

    if (rad->drt == nullptr) {
        int val = rad->data;
        Nod* temp = rad;
        rad = rad->stg;
        delete temp;
        return val;
    }
    
    return extractMax(rad->drt);
}
