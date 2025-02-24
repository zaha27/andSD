#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int *random_vector(int n) {
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        a[i] = rand() % 100 + 1;
    }
    return a;
}

void afisare_vector(int *a, int n) {
    for(int i = 0; i < n; i++){
        cout << a[i] << ' ';
    }
}

int main() {
    int *a, n;
    cout << "Introdu un numar : ";
    cin >> n;

    a = random_vector(n);
    afisare_vector(a, n);
    return 0;
}