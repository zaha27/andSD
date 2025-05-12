#include <iostream>
#include "header.h"
using namespace std;

int main() {
    Nod* rad = nullptr;

    insert(rad, 2);
    insert(rad, 3);
    insert(rad, 8);
    insert(rad, 7);

    cout << "max : " << topMax(rad) << '\n';

    cout << "descrescatoare\n";
    while (rad != nullptr) {
        cout << extractMax(rad) << " ";
    }

    cout << endl;
    return 0;
}
