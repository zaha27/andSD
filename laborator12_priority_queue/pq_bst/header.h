#ifndef HEADER_H_
#define HEADER_H_

struct Nod{
    int data;
    Nod* stg;
    Nod* drt;
};

void insert(Nod*& rad, int val);
int extractMax(Nod*& rad);
int topMax(Nod* rad);

#endif