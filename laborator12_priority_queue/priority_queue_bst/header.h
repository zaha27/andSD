#ifndef HEADER_H_
#define HEADER_H_

struct Nod{
    Nod* stg, drt;
    int data;
};

void insert(Nod*& rad, int val);
int extractMax(Nod*& rad);
int topMax(Nod* rad);

#endif