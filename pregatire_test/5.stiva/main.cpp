#include <iostream>
#include "stiva.h"
using namespace std;

int main() {
    Stack s = nullptr; // stiva goală

    push(s, 10);
    push(s, 20);
    push(s, 30);

    cout << "Vârful stivei: " << peek(s) << '\n'; // 30

    pop(s);
    cout << "Dupa pop, vârf: " << peek(s) << '\n'; // 20

    while (!isEmpty(s)) {
        cout << "Scot: " << peek(s) << '\n';
        pop(s);
    }

    destroyStack(s);
    cout << "Stiva e goala? " << (isEmpty(s) ? "DA" : "NU") << '\n';

    return 0;
}
