#ifndef _GRUPA_
#define _GRUPA_
#include "student.h"
struct Grupa {
 Student* tab;
 int nr; //numarul de studenti din grupa
 int id; // identificatorul grupei, de exemplu 1120A
};
void InitGrupa (Grupa&);
void AfisGrupa (Grupa);
void StergeGrupa (Grupa&);
#endif