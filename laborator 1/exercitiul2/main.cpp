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

void NotaMaximaSiNume(Grupa g) {
    int maxi = 1, mini = 10;
    int indiceMaxim, indiceMinim;
    for(int i = 0; i < g.nr; ++i) {
        if(maxi < g.tab[i].nota) {
            indiceMaxim = i;
            maxi = g.tab[i].nota;
        }
        if(mini > g.tab[i].nota) {
            indiceMinim = i;
            mini = g.tab[i].nota;
        }
    }
    cout << "Nota maxima este " << maxi << " si este luata de elevul " << g.tab[indiceMaxim].nume << '\n';
    cout << "Nota maxima este " << mini << " si este luata de elevul " << g.tab[indiceMinim].nume << '\n';
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

    NotaMaximaSiNume(g);

    StergeGrupa(g);

    return 0;
}
