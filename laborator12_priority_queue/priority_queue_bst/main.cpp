#include <iostream>
#include "header.h"

using namespace std;

int main() {
    //priroitaitea e chiar numaruil 
    insert(q, 10);
    insert(q, 5);
    insert(q, 20);
    insert(q, 15);

    cout << "scoase:\n";
    while (!isEmpty(q)) { 
        cout << extract(q) << " ";
    }
    cout << '\n';
    return 0;
}
