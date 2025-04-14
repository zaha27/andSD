#ifndef SPIRALA_H_
#define SPIRALA_H_

int **alocare_matrice(int n);
int **citire_matrice(int n);
void afisare_matrice_clasic(int **a, int n);
void afisare_matrice_spirala(int **a, int n);
void dealocare_matrice(int **a, int n);

#endif