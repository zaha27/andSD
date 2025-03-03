#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

struct Node {
    string nume;
    int telefon;  
    Node* succ; 
};

// Prototipuri pentru functii
void insertAtBeginning(Node *&head, string nume, int telefon);
void createList(Node *&head);
void displayList(Node *head);
void deleteList(Node *&head);
void searchList(Node *head, string value);

// Meniu pentru selectarea operatiilor
void selectareOperatie(Node *&head);

#endif
