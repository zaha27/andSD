#include <iostream>
#include "student.h"
#include "grupa.h"

void InitGrupa (Grupa& g) {
    std::cout << "Numarul de studenti: ";
    std::cin >> g.nr;
    g.tab = new Student[g.nr];
    for (int i = 0; i < g.nr; i++) {
        InitStudent(g.tab[i]);
    }
    std::cout << "Id grupa: ";
    std::cin >> g.id;
}

void AfisGrupa (Grupa g) {
    std::cout << "Id grupa: " << g.id << std::endl;
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

int main() {
    Grupa g;
    InitGrupa(g);
    AfisGrupa(g);
    StergeGrupa(g);
    return 0;
}