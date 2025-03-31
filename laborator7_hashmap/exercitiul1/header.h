#ifndef HEADER_H_
#define HEADER_H_

using namespace std;
#define M 137

struct Nod {
    char *cheie;
    Nod *urm;
};

void init(Nod* HT[]);
int hash(char *cuv);
void insert(Nod* HT[], char* cuv);
void sterge(Nod* HT[], char* cuv);
bool cautare(Nod* HT[], char* cuv);
void afisare(Nod* HT[]);


#endif