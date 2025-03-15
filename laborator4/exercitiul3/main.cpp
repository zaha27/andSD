#include <iostream>
#include "header.h"

int main() {
    Node* headUnu = 0;
    Node* headDoi = 0;

    createList(headUnu);
    displayList(headUnu);
    cout << '\n';

    createList(headDoi);
    displayList(headDoi);
    cout << '\n';

    //concatenareListe(headUnu, headDoi);

    interclasareListe(headUnu, headDoi);
    displayList(headUnu);

    return 0;
}