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
}

void displayPermutari(Node *head) {
    Node *temp = head;
    do {
        displayList(temp);
        cout << '\n';
        temp = temp->succ;
    } while (temp != head);
}

void reverseIterativ(Node *&head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    Node* tail = head;

     do {
        next = current->succ;  
        current->succ = prev;  
        prev = current;        
        current = next;        
    } while (current != head); 

    head -> succ = prev;
    head = prev;

    displayList(head);
}
