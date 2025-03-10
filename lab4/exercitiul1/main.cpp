#include <iostream>
#include "header.h"

int main() {
/* a */
    cout << "a) \n";
    Node* first = nullptr;
    Node* last = nullptr;
    createList(first, last);
/* b */ {
    cout << "b) \n";
    cout << "lista creata este: ";
    displayList(first, last);
    cout << "\n";
}       
/* c */ {
    cout << "c) \n";
    int value, position;
    cout << "Sa se introduca un numar pentru a il insera in lista: ";
    cin >> value;   //x 
    cout << "Sa se introduca o pozitie pentru inserarea valorii: ";
    cin >> position;   //pozitie 
    insertAtPosition(first, last, value, position);
    cout << "Lista afisata: ";
    displayList(first, last);
    cout << "\n";
}
/* d */ {
    cout << "e) \n";
    int position;
    cout << "Sa se introduca o pozitie pentru stergerea nodului: ";
    cin >> position;   
    deleteFromPosition(first, last, position);
    cout << "Lista afisata: ";
    displayList(first, last);
    cout << "\n";
} 
    return 0;
}