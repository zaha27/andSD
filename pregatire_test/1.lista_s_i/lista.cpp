#include <iostream>
#include "lista.h" 

using namespace std;


/*

Structura nodului (Nod)
struct Nod {
    int data;
    Nod* next;
};

Inserare la început

Inserare la final

Ștergere după valoare

Afișare listă

Eliberare memorie

(Opțional) Căutare valoare, Inserare după un anumit nod, Inversare listă


*/


void inserareInFata(Nod*& head, int val) {
    Nod* temp = new Nod;
    temp->data = val;
    temp->next = head;
    head = temp;
}
void inserareLaFinal(Nod*& head, int val) {
    Nod* temp = new Nod;
    temp->data = val;
    temp->next = nullptr;

    //parcurgem lista pana la ultimul element;
    if (head == nullptr) {
        head = temp;
    return;
    }
    Nod* p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    p->next = temp;
}
void stergere(Nod*& head, int val) {
    if (!head) return;

    if (head->data == val) {
        Nod* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Nod* p = head;
    while (p->next && p->next->data != val) {
        p = p->next;
    }

    if (p->next) {
        Nod* temp = p->next;
        p->next = temp->next;
        delete temp;
    }
}

void afisare(Nod* head) {
    for(Nod* p = head; p != nullptr; p = p->next) {
        cout << p->data << "->";
    }
    cout << "nullptr";
}
void stergeLista(Nod*& head) {
    while (head) {
        Nod* temp = head;
        head = head->next;
        delete temp;
    }
}