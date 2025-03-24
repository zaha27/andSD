#include "header.h"
#include <iostream>
using namespace std;

int main() {
    Queue Q;
    initQueue(Q);

    cout << "Adaugam elemente in coada: ";
    for (int i = 1; i <= 5; ++i) {
        cout << i << " ";
        put(Q, i);
    }
    cout << endl;

    cout << "Elementul din fata este: " << front(Q) << endl;

    cout << "Scoatem 2 elemente: ";
    cout << get(Q) << " ";
    cout << get(Q) << endl;

    //front
    cout << "Elementul din fata acum este: " << front(Q) << endl;

    //put
    cout << "Adaugam alte elemente: 6, 7, 8" << endl;
    put(Q, 6);
    put(Q, 7);
    put(Q, 8);


    //get
    cout << "Elementele ramase in coada: ";
    while (!isEmpty(Q)) {
        cout << get(Q) << " ";
    }
    cout << endl;

    return 0;
}
