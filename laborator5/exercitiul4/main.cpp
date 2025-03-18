#include <iostream>
#include "header.h"

using namespace std;

int main() {
    string expresie = "(9-5)+2";
    cin >> expresie;
    string expresie_postfixed = to_prefixed(expresie);
    cout << result_prefixed(expresie_postfixed);
    return 0;
}