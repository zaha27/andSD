#include <iostream>
#include "coada.h"
using namespace std;

int main() {
    Coada q;
    init(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    cout << "Primul element: " << peek(q) << '\n'; // 10

    dequeue(q);
    cout << "Dupa dequeue, primul: " << peek(q) << '\n'; // 20

    while (!isEmpty(q)) {
        cout << "Scot: " << peek(q) << '\n';
        dequeue(q);
    }

    destroyQueue(q);
    cout << "Coada e goala? " << (isEmpty(q) ? "DA" : "NU") << '\n';

    return 0;
}
