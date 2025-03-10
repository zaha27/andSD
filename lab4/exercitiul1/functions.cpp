#include <iostream>
#include "header.h"

void insertAtBeginning(Node *&first, Node *&last, int value) {
    Node* p = new Node(); 
    p->data = value;      
    p->pred = nullptr;
    p->succ = first;

    if (first != nullptr) {
        first->pred = p;  
    } else {
        last = p; 
    }

    first = p;             
}

void createList(Node *&first, Node *&last) {
    first = nullptr;
    last = nullptr;

    int n, value;
    cout << "Introduceti numarul de elemente: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Introduceti valoarea elementului " << i + 1 << ": ";
        cin >> value;
        insertAtBeginning(first, last, value);
    }
}

void displayList(Node *first, Node *last) {
    Node *p = first;
    while (p != nullptr) {
        cout << p->data << " ";
        p = p->succ;
    }
    cout << endl;
}

void deleteList(Node *&head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->succ;
        delete temp;
    }
}

void insertAtPosition(Node *&first, Node *&last, int value, int position) {
    if (position < 1) {
        cout << "Pozitia trebuie sa fie >= 1." << '\n';
        return;
    }

    if (position == 1) {
        insertAtBeginning(first, last, value);
        return;
    }

    Node* p = new Node(); 
    p->data = value;  
    p->succ = nullptr;
    p->pred = nullptr;   

    Node* temp = first;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->succ;
    }

    if (!temp) {
        cout << "Pozitie invalida." << '\n';
        delete p;
        return;
    }
    if (temp->succ == nullptr) {  
        temp->succ = p;
        p->pred = temp;
        last = p;
    } else {
        p->succ = temp->succ;
        p->pred = temp;
        temp->succ->pred = p;
        temp->succ = p;
    }        
}

void deleteFromPosition(Node *&first, Node *&last, int position) {
    if (position < 1) {
        cout << "Pozitia trebuie sa fie >= 1." << '\n';
        return;
    }

    if (first == nullptr) {
        cout << "Lista este goala!" << '\n';
        return;
    }

    if (position == 1) {
        Node* temp = first;
        first = first->succ;
        if (first) {
            first->pred = nullptr; 
        } else {
            last = nullptr; 
        }
        delete temp;
        return;
    }

    Node* temp = first;
    for (int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->succ;
    }

    if (!temp) {
        cout << "Pozitie invalida." << endl;
        return;
    }

    if (temp->pred) {
        temp->pred->succ = temp->succ; 
    }
    if (temp->succ) {
        temp->succ->pred = temp->pred;  
    }

    if (temp == last) {
        last = temp->pred;
    }

    delete temp; 
}