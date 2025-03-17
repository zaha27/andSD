#include <iostream>

using namespace std;

#define DIM_MAX 10

void push(int stiva[DIM_MAX], int &vf, int value) {
    if (vf < DIM_MAX - 1) {
        stiva[++vf] = value;
    } else {
        cerr << "Eroare: stiva plina" << endl;
    }
}

bool isEmpty(int vf) {
    return vf == -1;
}

bool pop(int &vf) {
    if (!isEmpty(vf)) {
        --vf;
        return true;
    } else {
        cerr << "Eroare: stiva goala" << endl;
        return false;
    }
}

int top(int stiva[DIM_MAX], int vf) {
    if (!isEmpty(vf)) {
        return stiva[vf];
    } 
    cerr << "Eroare: stiva goala" << endl;
    return -1;    
}

int main() {
    int stiva[DIM_MAX];
    int vf = -1; 

    push(stiva, vf, 10);
    push(stiva, vf, 20);
    push(stiva, vf, 30);

    cout << "varf: " << top(stiva, vf) << endl;
    pop(vf);
    cout << "varf dupa pop: " << top(stiva, vf) << endl;

    while (!isEmpty(vf)) {
        pop(vf);
    }

    bool rezultat = isEmpty(vf);
    cout << "stiva goala (true/false):  " << rezultat << endl;

    return 0;
}
