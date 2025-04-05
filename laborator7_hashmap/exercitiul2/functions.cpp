#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "header.h"

using namespace std;

int my_hash_one(int key) {
    return key % M;
}

int my_hash_two(char* key) {
    unsigned long h = 5381;
    int c;
    while ((c = *key++))
        h = ((h << 5) + h) + c; // h * 33 + c
    return h % M;
}

int my_hash_three(int key) {
    double A = 0.6180339887;
    double val = key * A;
    double fract = val - (int)val;
    return (int)(M * fract);
}

void init(Nod* HT[]) {
    for (int i = 0; i < M; ++i)
        HT[i] = nullptr;
}

void insert_int(Nod* HT[], int x, HashIntType hash_type) {
    char buffer[20];
    sprintf(buffer, "%d", x);

    if (cautare(HT, buffer)) return;

    Nod* p = new Nod;
    p->cheie = strdup(buffer);

    int h;
    if (hash_type == HASH_ONE)
        h = my_hash_one(x);
    else
        h = my_hash_three(x);

    p->urm = HT[h];
    HT[h] = p;
}

void insert_char(Nod* HT[], char* cuv) {
    if (cautare(HT, cuv)) return;

    Nod* p = new Nod;
    p->cheie = strdup(cuv);

    int h = my_hash_two(cuv);

    p->urm = HT[h];
    HT[h] = p;
}

void sterge(Nod* HT[], char* cuv) {
    int h = my_hash_two(cuv);
    Nod* p = HT[h], *prev = nullptr;
    while (p) {
        if (strcmp(p->cheie, cuv) == 0) {
            if (prev) prev->urm = p->urm;
            else HT[h] = p->urm;
            free(p->cheie);
            delete p;
            return;
        }
        prev = p;
        p = p->urm;
    }
}

bool cautare(Nod* HT[], char* cuv) {
    int h = my_hash_two(cuv);
    for (Nod* p = HT[h]; p; p = p->urm)
        if (strcmp(p->cheie, cuv) == 0)
            return true;
    return false;
}

void afisare(Nod* HT[]) {
    for (int i = 0; i < M; i++) {
        if (HT[i]) {
            cout << "Slot " << i << ": ";
            for (Nod* p = HT[i]; p; p = p->urm)
                cout << p->cheie << " -> ";
            cout << "nullptr\n";
        }
    }
}

double cluster_functions(Nod* HT[], int NUMAR) {
    int x[NUMAR] = {0};
    int N = 0;

    for (int i = 0; i < NUMAR; ++i) {
        Nod* p = HT[i];
        while (p) {
            x[i]++;
            N++;
            p = p->urm;
        }
    }

    if (N == 0) {
        cout << "Tabela este goala.\n";
        return 0;
    }

    double alpha = (double)N / NUMAR;
    double sum_xi2 = 0;

    for (int i = 0; i < NUMAR; ++i)
        sum_xi2 += x[i] * x[i];

    double C = sum_xi2 / (N - alpha);
    return C;
}


void afisareTabel() {
    const int M1 = 50;
    const int M2 = 75;
    const int M3 = 100;

    Nod* HT1_1[M1] = {}; // H1, f1
    Nod* HT1_2[M1] = {}; // H1, f2
    Nod* HT1_3[M1] = {}; // H1, f3

    Nod* HT2_1[M2] = {};
    Nod* HT2_2[M2] = {};
    Nod* HT2_3[M2] = {};

    Nod* HT3_1[M3] = {};
    Nod* HT3_2[M3] = {};
    Nod* HT3_3[M3] = {};

    srand(time(NULL)); // seed pentru rand()

    char buffer[20];
    // --- Umplem tabelele ---
    for (int i = 0; i < M1 + 30; i++) {
        int val = rand() % 1000;
        insert_int(HT1_1, val, HASH_ONE);
        insert_int(HT1_2, val, HASH_THREE);
        sprintf(buffer, "%d", val);
        insert_char(HT1_3, buffer);
    }

    for (int i = 0; i < M2 + 30; i++) {
        int val = rand() % 1000;
        insert_int(HT2_1, val, HASH_ONE);
        insert_int(HT2_2, val, HASH_THREE);
        sprintf(buffer, "%d", val);
        insert_char(HT2_3, buffer);
    }

    for (int i = 0; i < M3 + 30; i++) {
        int val = rand() % 1000;
        insert_int(HT3_1, val, HASH_ONE);
        insert_int(HT3_2, val, HASH_THREE);
        sprintf(buffer, "%d", val);
        insert_char(HT3_3, buffer);
    }

    cout << "\nTabele generate cu valori random si 3 functii de dispersie:\n";
    cout << "------------------------------------------------------------\n";
    cout << "| M    |   f1 (int%)  |   f2 (int*A) |   f3 (Bernstein str) |\n";
    cout << "------------------------------------------------------------\n";

    double C11 = cluster_functions(HT1_1, M1);
    double C12 = cluster_functions(HT1_2, M1);
    double C13 = cluster_functions(HT1_3, M1);

    double C21 = cluster_functions(HT2_1, M2);
    double C22 = cluster_functions(HT2_2, M2);
    double C23 = cluster_functions(HT2_3, M2);

    double C31 = cluster_functions(HT3_1, M3);
    double C32 = cluster_functions(HT3_2, M3);
    double C33 = cluster_functions(HT3_3, M3);

    printf("| %-4d | %-12.4f | %-12.4f | %-18.4f |\n", M1, C11, C12, C13);
    printf("| %-4d | %-12.4f | %-12.4f | %-18.4f |\n", M2, C21, C22, C23);
    printf("| %-4d | %-12.4f | %-12.4f | %-18.4f |\n", M3, C31, C32, C33);
    cout << "------------------------------------------------------------\n";
}
