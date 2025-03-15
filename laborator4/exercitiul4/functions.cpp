#include <iostream>
#include "header.h"

void insertAtBeginning(Node *&head, int value) {
    Node* p = new Node(); 
    p->data = value;   
    
    if(head == nullptr) {
        p->succ = p;
        head = p;
    } else {
        p->succ = head->succ;
        head->succ = p;       
        swap(head->data, p->data);             
    }
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
    do {
        cout << temp->data << " -> ";
        temp = temp->succ;
    } while (temp != head);
    cout << "(back to head)\n";
}

void deleteNode(Node *&head, Node *&toDelete) {
    if (head == nullptr || toDelete == nullptr) return;

    if (head == toDelete && head->succ == head) { // Un singur nod
        delete head;
        head = nullptr;
        return;
    }

    Node *prev = head;
    while (prev->succ != toDelete) {
        prev = prev->succ;
    }

    prev->succ = toDelete->succ;

    if (toDelete == head) {
        head = toDelete->succ;
    }

    delete toDelete;
}

void afisareExecuted(Node *&head, int n, int m) {
    Node *p = head;
    while (n >= m) {
        for (int i = 1; i < m; i++) {
            p = p->succ;
        }
        cout << "Eliminat: " << p->data << endl;
        Node *toDelete = p;
        p = p->succ;
        deleteNode(head, toDelete);
        n--;
    }
    cout << "Supravietuitor: ";
    displayList(head);
}