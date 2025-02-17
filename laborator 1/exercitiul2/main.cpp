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
    StergeGrupa(g);

    return 0;
}
