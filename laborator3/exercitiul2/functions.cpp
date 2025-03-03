#include <iostream>
#include "header.h"

using namespace std;

void insertAtBeginning(Node *&head, string nume, int telefon) {
    Node* p = new Node(); 
    p->nume = nume;
    p->telefon = telefon;      
    p->succ = head;       
    head = p;             
}

void createList(Node *&head) {
    int n, telefon;
    string nume;
    cout << "Introduceti numarul de persoane: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Introduceti numele persoanei " << i + 1 << ": ";
        cin >> nume;
        cout << "Introduceti numele de telefon a persoanei " << nume << ": ";   
        cin >> telefon;
        insertAtBeginning(head, nume, telefon);
    }
}

void displayList(Node *head) {
    Node* temp = head;
    while (temp) {
        cout << "Nume persoana: " << temp -> nume;
        cout << " Telefon persoana: " << temp -> telefon;
        cout << '\n';
        temp = temp->succ;
    }
}

void deleteList(Node *&head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->succ;
        delete temp;
    }
    head = 0; 
}


void searchList(Node *head, string value) {
    int contor = 0;
    Node* p = head;
    while (p) {
        contor++;
        if (p->nume == value) {
            cout << "Persoana " << value << " a fost gasita la pozitia " << contor << '\n';
            cout << "Nr. acesteia de telefon este: " << p->telefon << '\n';
            return;
        }
        p = p->succ;
    }
    cout << "Persoana nu a fost gasita!" << '\n';
}

void selectareOperatie(Node *&head) {
    int alegere;
    do {
        cout << "\nMeniu operatii:\n";
        cout << "1. Introducere persoane\n";
        cout << "2. Afisare lista\n";
        cout << "3. Cautare persoana\n";
        cout << "4. Stergere lista\n";
        cout << "0. Iesire\n";
        cout << "Alege operatia (0-4): ";
        cin >> alegere;

        switch (alegere) {
            case 1:
                createList(head);
                break;
            case 2:
                displayList(head);
                break;
            case 3: {
                string nume;
                cout << "Introduceti numele persoanei cautate: ";
                cin >> nume;
                searchList(head, nume);
                break;
            }
            case 4:
                deleteList(head);
                cout << "Lista a fost stearsa.\n";
                break;
            case 0:
                cout << "Iesire din program.\n";
                break;
            default:
                cout << "Optiune invalida!\n";
        }
    } while (alegere != 0);
}
