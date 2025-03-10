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
} /* c */ {
    cout << "c) \n";
    cout << "permutarile circulare sunt: ";
    displayPermutari(head);
    cout << "\n";
} /* d */ {
    cout << "d) \n";
    cout << "lista inversata este: ";
    reverseIterativ(head);
    cout << "\n";
}        
    return 0;
}