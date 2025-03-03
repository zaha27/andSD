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

void searchList(Node *head, int value) {
    int contor = 0;
    Node* p = new Node;
    for(p = head; p -> succ; p = p -> succ) {
        contor++;
        if(p -> data == value) {
            cout << "Valoarea " << value << " a fost gasita la pozitia " << contor << '\n';
            return ;
        }
    }
}

void insertAtPosition(Node *&head, int value, int position) {
        if (position < 1) {
            cout << "Pozitia trebuie sa fie >= 1." << '\n';
            return;
        }

        if (position == 1) {
            insertAtBeginning(head, value);
            return;
        }

        Node* p = new Node(); 
        p->data = value;     

        Node* temp = head;
        for (int i = 1; i < position - 1 && temp; ++i) {
            temp = temp->succ;
        }

        if (!temp) {
            cout << "Pozitie invalida." << '\n';
            delete p;
            return;
        }

        p->succ = temp->succ;
        temp->succ = p;
}

void deleteFromPosition(Node *&head, int position) {
    if (position < 1) {
            cout << "Pozitia trebuie sa fie >= 1." << '\n';
            return;
        }
    if (position == 1) {
            cout << "Nu mai este niciun nod in lista" << '\n';
            return;
        }
    Node* temp = head;
    for(int i = 1; i < position - 1 && temp; ++i) {
        temp = temp->succ;
    }
    if (!temp || !temp->succ) {
            cout << "Pozitie invalida." << endl;
            return;
        }
    Node* nodeToDelete = temp->succ; 
    temp->succ = temp->succ->succ;   
    delete nodeToDelete;  
}