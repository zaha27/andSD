#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>

using namespace std;

#define M 100  // val general default pt hashuri (dacă ai nevoie)
#define M1 50
#define M2 75
#define M3 100

struct Nod {
    char* cheie;
    Nod* urm;
};

enum HashIntType {
    HASH_ONE,
    HASH_THREE
};

// funcții hash
int my_hash_one(int x);
int my_hash_two(char* cuv);
int my_hash_three(int x);

// operații pe tabelă
void init(Nod* HT[]);
void insert_int(Nod* HT[], int x, HashIntType tip);
void insert_char(Nod* HT[], char* cuv);
void sterge(Nod* HT[], char* cuv);
bool cautare(Nod* HT[], char* cuv);
void afisare(Nod* HT[]);
double cluster_functions(Nod* HT[], int NUMAR);

// benchmark
void afisareTabel();

#endif
