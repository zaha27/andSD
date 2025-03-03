#include <iostream>
#include "header.h"

int main() {
/* a */
    cout << "a) \n";
    Node* head = NULL;
    createList(head);
/* b */
    cout << "b) \n";
    cout << "lista creata este: ";
    displayList(head);
    cout << "\n";
/* c */
    cout << "c) \n";
    int value;
    cout << "Sa se introduca un numar pentru a il cauta in lista: ";
    cin >> value;   //x 
    searchList(head, value);
    cout << "\n";
/* d */

    return 0;
}