#include <iostream>
#include "header.h"

using namespace std;

void RSS(AVL*& a) {
    AVL* b = a->stg;
    a->stg = b->drt;
    b->drt = a;
    a->bf = b->bf = 0;
    a = b; // b devine noua radacina
}

void RSD(AVL*& a) {
    AVL* b = a->drt;
    a->drt = b->stg;
    b->stg = a;
    a->bf = b->bf = 0;
    a = b; // b devine noua radacina
}

void RDS(AVL*& a) {
    AVL* b = a->drt;
    AVL* c = b->stg;
    
    // Actualizare factori de echilibru
    switch (c->bf) {
        case 0:
            a->bf = b->bf = 0;
            break;
        case 1:
            a->bf = 0;
            b->bf = -1;
            break;
        case -1:
            a->bf = 1;
            b->bf = 0;
            break;
    }
    
    // Refacere legaturi
    b->stg = c->drt;
    a->drt = c->stg;
    c->drt = b;
    c->stg = a;
    c->bf = 0;
    
    // c devine noua radacina
    a = c;
}

void RDD(AVL*& a) {
    AVL* b = a->stg;
    AVL* c = b->drt;
    
    // Actualizare factori de echilibru
    switch (c->bf) {
        case 0:
            a->bf = b->bf = 0;
            break;
        case 1:
            a->bf = -1;
            b->bf = 0;
            break;
        case -1:
            a->bf = 0;
            b->bf = 1;
            break;
    }
    
    // Refacere legaturi
    b->drt = c->stg;
    a->stg = c->drt;
    c->stg = b;
    c->drt = a;
    c->bf = 0;
    
    // c devine noua radacina
    a = c;
}
