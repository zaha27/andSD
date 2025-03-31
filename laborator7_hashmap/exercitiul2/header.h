#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

#define M1 50
#define M2 75
#define M3 100

struct Nod {
    char *cheie;
    Nod *urm;
};

void init(Nod* HT[]);
int my_hash_one(int x);
int my_hash_two(char *cuv);
int my_hash_three(int x);
void insert(Nod* HT[], char* cuv);
void sterge(Nod* HT[], char* cuv);
bool cautare(Nod* HT[], char* cuv);
void afisare(Nod* HT[]);


#endif