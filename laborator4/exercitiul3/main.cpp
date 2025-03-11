#include <iostream>
#include "header.h"

int main() {
    Node* headUnu = 0;
    Node* headDoi = 0;

    createList(headUnu);
    displayList(headUnu);

    createList(headDoi);
    displayList(headDoi);

    concatenareListe(headUnu, headDoi);

    //interclasareListe(headUnu, headDoi);
    displayList(headUnu);
    displayList(headDoi);

    return 0;
}