#include <iostream>
#include <cstring>
#include "grupa.h"

using namespace std;

void cautaStudent(Grupa g, char *nume) {
    for(int i = 0; i < g.nr; ++i) {
        if(strcmp(g.tab[i].nume, nume) == 0) {
            cout << "Nota studentului: " << g.tab[i].nota << endl;
            return;
        }
    }
    cout << "Studentul nu a fost gasit!" << endl;
}

void NotaMaxima(Grupa g) {
    int maxi = 1, mini = 10;
    for(int i = 0; i < g.nr - 1; ++i) {
        maxi = max(g.tab[i].nota,g.tab[i + 1].nota);
        mini = min(g.tab[i].nota,g.tab[i + 1].nota);
    }
    cout << "Nota maxima: " << maxi << '\n';
    cout << "Nota minima: " << mini << '\n';
}

int main() {
    Grupa g;
    InitGrupa(g);
    AfisGrupa(g);

    cout << "Numele elevului cautat: ";
    char buffer[50];
    cin.ignore(100, '\n'); 
    cin.getline(buffer, 50);

    char *numeCautat = new char[strlen(buffer) + 1];
    strcpy(numeCautat, buffer);

    cautaStudent(g, numeCautat);

    delete[] numeCautat;

    cout << endl;
    cout << "Gasire nota maxima si minima" << '\n';

    NotaMaxima(g);

    StergeGrupa(g);

    return 0;
}
