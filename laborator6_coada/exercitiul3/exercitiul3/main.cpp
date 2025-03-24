#include "header.h"
#include <iostream>
using namespace std;

int main() {
    Queue Q;
    initQueue(Q);

    put(Q, 1);
    put(Q, 2);
    put(Q, 3);

    cout << front(Q) << " ";  // 1
    cout << get(Q) << " ";    // 1
    cout << get(Q) << " ";    // 2

    put(Q, 4);
    cout << front(Q) << " ";  // 3
    cout << get(Q) << " ";    // 3
    cout << get(Q) << endl;   // 4

    return 0;
}
