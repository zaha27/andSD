#ifndef HASH_LAB_H
#define HASH_LAB_H

const int M = 10;

struct Nod {
    int info;
    Nod* next;
};

typedef Nod* HashTable[M];

void init(HashTable& h);
int hashFunction(int val); // returnează val % M
void insert(HashTable& h, int val);
bool search(HashTable h, int val);
bool remove(HashTable& h, int val);
void display(HashTable h);
void destroy(HashTable& h);

#endif
