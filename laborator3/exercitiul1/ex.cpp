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
/* c */ {
    cout << "c) \n";
    int value;
    cout << "Sa se introduca un numar pentru a il cauta in lista: ";
    cin >> value;   //x 
    searchList(head, value);
    cout << "\n";
}
/* d */ {
    cout << "d) \n";
    int value, position;
    cout << "Sa se introduca un numar pentru a il insera in lista: ";
    cin >> value;   //x 
    cout << "Sa se introduca o pozitie pentru inserarea valorii: ";
    cin >> position;   //pozitie 
    insertAtPosition(head, value, position);
    cout << "Lista afisata: ";
    displayList(head);
    cout << "\n";
} 
/* e */ {
    cout << "e) \n";
    int position;
    cout << "Sa se introduca o pozitie pentru stergerea nodului: ";
    cin >> position;   
    deleteFromPosition(head, position);
    cout << "Lista afisata: ";
    displayList(head);
    cout << "\n";
}
/* f */ {
    cout << "f) \n";
    int position;
    cout << "Sa se introduca o pozitie (coada -> cap): ";
    cin >> position;   
    afisareCoadaCap(head, position);
    cout << "\n";
}
/* g */ {
    cout << "f) \n";   
    reverse(head);
    cout << "\n";
}
    return 0;
}