#include <iostream>
#include "hash_lab.h"
using namespace std;

void init(HashTable& h) {
    for(int i = 0; i < M; ++i) {
        h[i] = nullptr;
    }
}
int hashFunction(int key) {
    return key % M;
}
bool search(HashTable h, int val) {
    int pos = hashFunction(val); // afli poziția
    Nod* p = h[pos];             // parcurgi lanțul

    for (; p != nullptr; p = p->next) {
        if (p->info == val) {
            return true;
        }
    }
    return false;
}

void insert(HashTable& h, int val) {
    int poz = hashFunction(val);
    
    Nod* temp = new Nod;
    temp->info = val;

    //inseram la pozitia poz la inceputul listei
    if(h[poz] == nullptr) {
        h[poz] = temp;
        temp->next = nullptr;
    } else {
        Nod *aux = h[poz];
        h[poz] = temp;
        temp->next = aux;
    }
}
bool remove(HashTable& h, int val) {
    int poz = hashFunction(val);
    Nod* p = h[poz];

    // cazul în care primul nod trebuie șters
    if (p && p->info == val) {
        h[poz] = p->next;
        delete p;
        return true;
    }

    // parcurgem restul listei
    while (p && p->next) {
        if (p->next->info == val) {
            Nod* temp = p->next;
            p->next = temp->next;
            delete temp;
            return true;
        }
        p = p->next;
    }

    return false; // nu s-a găsit
}

void display(HashTable h) {
    for (int i = 0; i < M; ++i) {
        cout << "[" << i << "]: ";
        if (h[i] == nullptr) {
            cout << "nullptr\n";
        } else {
            for (Nod* p = h[i]; p != nullptr; p = p->next) {
                cout << p->info << " -> ";
            }
            cout << "nullptr\n";
        }
    }
}

void destroy(HashTable& h) {
    for (int i = 0; i < M; ++i) {
        Nod* p = h[i];
        while (p != nullptr) {
            Nod* temp = p;
            p = p->next;
            delete temp;
        }
        h[i] = nullptr;
    }
}


