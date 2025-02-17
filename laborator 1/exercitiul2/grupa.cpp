#include <iostream>
#include "grupa.h"

using namespace std;

void InitGrupa (Grupa& g) {
    cout << "Numarul de studenti: ";
    cin >> g.nr;
    g.tab = new Student[g.nr];
    for (int i = 0; i < g.nr; i++) {
        InitStudent(g.tab[i]);
    }
    cout << "Id grupa: ";
    cin >> g.id;
}

void AfisGrupa (Grupa g) {
    cout << "Id grupa: " << g.id << endl;
    for (int i = 0; i < g.nr; i++) {
        AfisStudent(g.tab[i]);
    }
}

void StergeGrupa (Grupa& g) {
    for (int i = 0; i < g.nr; i++) {
        StergeStudent(g.tab[i]);
    }
    delete[] g.tab;
    g.tab = nullptr;
    g.nr = 0;
    g.id = 0;
}
