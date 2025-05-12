#include <iostream>
#include "header.h"

using namespace std;

int main() {
    Queue q;
    initQueue(q);

    //priroitaitea e chiar numaruil 
    put(q, 10);
    put(q, 5);
    put(q, 20);
    put(q, 15);

    cout << "scoase:\n";
    while (!isEmpty(q)) { 
        cout << get(q) << " ";
    }
    cout << '\n';
    return 0;
}
