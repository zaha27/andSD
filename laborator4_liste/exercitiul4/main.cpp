#include <iostream>
#include "header.h"

int main() {
    Node *head = nullptr;
    createList(head);
    cout << "Lista initiala: \n";
    displayList(head);

    int m;
    cout << "Introduceti valoarea lui m: ";
    cin >> m;

    afisareExecuted(head, 7, m);
    return 0;
}
