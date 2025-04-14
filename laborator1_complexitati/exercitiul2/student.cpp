#include <iostream>
#include <cstring>
#include "student.h"

using namespace std; 

void InitStudent(Student& s) {
    char buffer[100];
    cin.ignore(); 
    cout << "Nume: ";
    cin.getline(buffer, 100);
    s.nume = new char[strlen(buffer) + 1];
    strcpy(s.nume, buffer);
    
    cout << "Nota: ";
    cin >> s.nota;
}

void AfisStudent(Student s) {
    cout << "Nume: " << s.nume << endl;
    cout << "Nota: " << s.nota << endl;
}   

void StergeStudent(Student& s) {
    delete[] s.nume;
    s.nume = nullptr;
    s.nota = 0;
}
