#include <iostream>
#include "lista_circulara.h"
using namespace std;

// Adaugă un element înainte de head, fără a schimba head-ul
void inserareInFata(Nod*& head, int val) {
    Nod* temp = new Nod;
    temp->data = val;

    if (head == nullptr) {
        // Prima inserare → nodul se leagă la el însuși
        temp->next = temp;
        head = temp;
    } else {
        // temp se inserează imediat după head, dar head rămâne neschimbat
        temp->next = head->next;
        head->next = temp;
    }
}

// Adaugă un element după ultimul nod (înainte de head) și menține head neschimbat
void inserareLaFinal(Nod*& head, int val) {
    Nod* temp = new Nod;
    temp->data = val;

    if (head == nullptr) {
        // Primul nod din listă: se leagă la el însuși
        temp->next = temp;
        head = temp;
    } else {
        // Parcurgem până la ultimul nod (p->next == head)
        Nod *p = head;
        while (p->next != head) {
            p = p->next;
        }
        // Inserăm temp după ultimul nod și legăm la head
        p->next = temp;
        temp->next = head;
    }
}

// Afișează elementele din lista circulară
void afisare(Nod* head) {
    if (head == nullptr) {
        cout << "nullptr\n";
        return;
    }

    Nod *p = head;
    do {
        cout << p->data << " -> ";
        p = p->next;
    } while (p != head);
    cout << "(circular)\n";
}

// Șterge toate nodurile din lista circulară
void stergeLista(Nod*& head) {
    if (head == nullptr) return;

    Nod* p = head->next;
    while (p != head) {
        Nod* temp = p;
        p = p->next;
        delete temp;
    }

    // Ultimul nod (head) e șters separat
    delete head;
    head = nullptr;
}
