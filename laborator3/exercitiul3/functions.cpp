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

void concatenareListe(Node *&head, Node *secundar) {
    Node* p = head;
    Node* save = head;
    for(; p -> succ; p = p -> succ);
    p -> succ = secundar;
    head = save;
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

    // Dacă mai sunt elemente rămase într-una din liste
    if (head) tail->succ = head;
    else tail->succ = secundar;

    head = dummy->succ;  // Mutăm `head` la începutul noii liste
    delete dummy;
}
