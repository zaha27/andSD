#include <iostream>
#include "hash_lab.h"
using namespace std;

int main() {
    HashTable h;
    init(h);

    insert(h, 7);
    insert(h, 12);
    insert(h, 3);
    insert(h, 17);

    display(h);

    if (search(h, 12)) {
        cout << "12 se gaseste in tabela.\n";
    }

    remove(h, 7);
    cout << "Dupa stergere:\n";
    display(h);

    destroy(h);
    return 0;
}
