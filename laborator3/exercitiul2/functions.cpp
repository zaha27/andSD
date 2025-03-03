#include <iostream>
#include "header.h"



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
        cout << "Telefon persoana: " << temp -> telefon;
        cout << '\n';
    }
    cout << "NULL" << '\n';
}

void deleteList(Node *&head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->succ;
        delete temp;
    }
}

void searchList(Node *head, string value) {
    int contor = 0;
    Node* p = new Node;
    for(p = head; p ; p = p -> succ) {
        contor++;
        if(p -> nume == value) {
            cout << "Persoana " << value << " a fost gasita la pozitia " << contor << '\n';
            cout << "Nr. acesteia de telefon este: " << p -> telefon;
            return ;
        }
    }
}