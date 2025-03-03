#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

struct Node {
    string nume;
    int telefon;  
    Node* succ; 
};

//meniu pointer la o functie pentru a primi operatia necesara
void (*selectareOperatie(void))(void);

void insertAtBeginning(Node *&head, string nume, int telefon);
void createList(Node *&head);
void displayList(Node *head);
void deleteList(Node *&head, string nume);
void searchList(Node *head, string nume);

#endif