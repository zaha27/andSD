#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

struct Node {
    int data;  
    Node* succ; 
    Node* pred;
};

void insertAtBeginning(Node *&first, Node *&last, int value);
void createList(Node *&first, Node *&last);
void displayList(Node *first, Node *last);
void insertAtPosition(Node *&first, Node *&last, int value, int position);
void deleteFromPosition(Node *&first, Node *&last, int position);
void deleteList(Node *&head);


#endif