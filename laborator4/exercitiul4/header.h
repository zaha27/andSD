#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

struct Node {
    int data;  
    Node* succ; 
};

void insertAtBeginning(Node *&head, int value);
void createList(Node *&head);
void displayList(Node *head);
void deleteList(Node *&head);
void afisareExecuted(Node *&head, int n, int m);

#endif