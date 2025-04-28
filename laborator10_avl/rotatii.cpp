#include <iostream>
#include "header.h"

void RSS(AVL*& a) {
    AVL* b = a->stg;
    a->stg = b->drt;
    b->drt = a;
    a->bf = b->bf = 0;
    a = b; // b devine noua radacina
}
void RSD(AVL *&a) {
    AVL* b = a->drt;
    a->drt = b->stg;
    b->stg = a;
    a->bf = b->bf = 0;
    a = b;
}
void RDS(AVL *&a) {

}
void RDD(AVL *&a) {

}