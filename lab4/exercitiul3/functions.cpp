#include <iostream>
#include "header.h"

void insertAtBeginning(Node *&head, int value) {
    Node* p = new Node(); 
    p->data = value;      
    p->succ = head;       
    head = p;             
}

void createList(Node *&head) {
    int n, value;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Introduceti valoarea elementului " << i + 1 << ": ";
        cin >> value;
        insertAtBeginning(head, value);
    }
}

void displayList(Node *head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " -> ";
        temp = temp->succ;
    }
    cout << "head\n";
}

void deleteList(Node *&head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->succ;
        delete temp;
    }
}

void concatenareListe(Node *&head, Node *secundar) {
    if (head == nullptr && secundar == nullptr) return;

    if (head == nullptr) {
        head = secundar;
        return;
    }

    if (secundar == nullptr) {
        return;
    }

    Node* p = head;
    while (p->succ != head) {
        p = p->succ;
    }

    Node* q = secundar;
    while (q->succ != secundar) {
        q = q->succ;
    }

    p->succ = secundar;
    q->succ = head;
}

void interclasareListe(Node *&head, Node *secundar) {
    Node* dummy = new Node();  
    Node* tail = dummy;       
    
    while (head && secundar) {
        if (head->data <= secundar->data) {
            tail->succ = head;
            head = head->succ;
        } else {
            tail->succ = secundar;
            secundar = secundar->succ;
        }
        tail = tail->succ;
    }

    if (head) tail->succ = head;
    else tail->succ = secundar;

    head = dummy->succ;  
    delete dummy;
}