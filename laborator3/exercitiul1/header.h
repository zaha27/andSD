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
void searchList(Node *head, int value);
void insertAtPosition(Node *&head, int value, int position);
void deleteFromPosition(Node *&head, int position);
void afisareCoadaCap(Node *head, int pozitie);
void reverseIterativ(Node *&head);
Node* reverseRecursive(Node* head);
void reverseWithStack(Node *&head);
void displayListInvers(Node *head);
void afisareMijloc(Node *head);
void areBucle(Node *head);
#endif