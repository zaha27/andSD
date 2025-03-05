#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

struct Node {
    int data;  
    Node* succ; 
};

void insertAtBeginning(Node *&head, int value);
void insertAtPosition(Node *&head, int value, int position);
void createList(Node *&head);
void displayList(Node *head);
int noNodes(Node *&head);
void deleteList(Node *&head);
void concatenareListe(Node *&head, Node *secundar);
void interclasareListe(Node *&head, Node *secundar);

#endif