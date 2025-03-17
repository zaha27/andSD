#include <iostream>
#include "header.h"

using namespace std;

int main() {
    string expresie = "";
    cin >> expresie;
    string expresie_postfixed = to_postfixed(expresie);
    cout << result_postfixed(expresie_postfixed);
    return 0;
}