#include <iostream>
#include "student.h"

void InitStudent(Student& s) {
    s.nume = new char[100];
    std::cout << "Nume: ";
    std::cin >> s.nume;
    std::cout << "Nota: ";
    std::cin >> s.nota;
}

void AfisStudent(Student s) {
    std::cout << "Nume: " << s.nume << std::endl;
    std::cout << "Nota: " << s.nota << std::endl;
}   

void StergeStudent(Student& s) {
    delete[] s.nume;
    s.nume = nullptr;
    s.nota = 0;
}

int main() {
    Student s;
    InitStudent(s);
    AfisStudent(s);
    StergeStudent(s);
    return 0;
}