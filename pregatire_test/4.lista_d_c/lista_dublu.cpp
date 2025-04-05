#include <iostream>
#include "lista_dublu_circulara.h"

using namespace std;

/*
 *struct Nod {
 *   int data;
 *   Nod* next;
 *   Nod* prev;
 *};
 */

void inserareInFata(Nod*& head, int val) {
    Nod* temp = new Nod;
    temp->data = val;


    if(head == nullptr) {
        temp->prev = temp;
        temp->next = temp;
        head = temp;
        return;
    }

    temp->next = head;
    temp->prev = head->prev;

    head->prev->next = temp;
    head->prev = temp;

    head = temp;
}

void inserareLaFinal(Nod*& head, int val) {
    Nod* temp = new Nod;
    temp->data = val;

    if (head == nullptr) {
        temp->prev = temp;
        temp->next = temp;
        head = temp;
        return;
    }

    Nod* ultim = head->prev;

    temp->next = head;
    temp->prev = ultim;

    ultim->next = temp;
    head->prev = temp;
}


void afisareStangaDreapta(Nod* head) {
    if(head == nullptr) {
        cout << "nullptr";
        return ;
    }
    for(Nod* p = head; p != head->next; p = p->next) {
        cout << p->data << "<->";
    }
    cout << "nullptr";
}
void afisareDreaptaStanga(Nod* head) {
    if(head == nullptr) {
        cout << "nullptr";
        return ;
    }

    Nod* p = head;
    while(p->next != nullptr) {
        p = p->next;
    }
    while(p->prev != head->prev) {
        cout << p->data << "<->";
        p = p->prev;
    }
    cout << "nullptr";
}
void stergere(Nod*& head, int val) {
    if(head == nullptr) {
        return;
    }
    Nod* temp = head, *p = head;
    while(p -> data != val) {
        p = p->next;
    }
    temp = p->next;
    p->next = p->next->next;
    delete temp;
}
void stergeLista(Nod*& head) {
    Nod* temp, *p = head;
    while(p != nullptr) {
        temp = p;
        p = p->next;
        delete temp;
    }
}


