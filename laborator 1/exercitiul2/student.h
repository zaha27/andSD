#ifndef _STUDENT_
#define _STUDENT_

struct Student {
 char* nume;
 int nota;
};
void InitStudent (Student&);
void AfisStudent (Student);
void StergeStudent (Student&);

#endif