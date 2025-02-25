#include <iostream>
#include "smax.h"

using namespace std;

int main() {
    int n;
    cout << "Introdu dimensiunea vectorului: ";
    cin >> n;

    int *v = alocare_vector(n);

    cout << "Introdu elementele vectorului: ";
    citire_vector(v, n);

    //
        int smax;
        smax = smax_optim(v, n);
    //

    cout << "Secventa maxima este: ";
    cout << smax << '\n';

    dealocare_vector(v);

    return 0;
}
