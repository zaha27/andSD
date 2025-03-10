#include <iostream>
#include "header.h"

int main() {
/* a */
    cout << "a) \n";
    Node* head = NULL;
    createList(head);
/* b */ {
    cout << "b) \n";
    cout << "lista creata este: ";
    displayList(head);
    cout << "\n";
}       
    return 0;
}