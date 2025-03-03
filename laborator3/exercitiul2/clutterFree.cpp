#include <iostream>
#include "header.h"

int main() {

    Node* head = NULL;
    createList(head);

    void (*operatie)(Node*) = 0;
    operatie = selectareOperatie(head);

    cout << "lista creata este: ";
    displayList(head);
    cout << "\n";

    return 0;
}