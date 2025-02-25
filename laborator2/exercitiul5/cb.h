#ifndef CB_H_
#define CB_H_

int **alocare_matrice(int n);
int **citire_matrice(int n);
void afisare_matrice_clasic(int **a, int n);
void rotire_matrice(int **a, int n);
void dealocare_matrice(int **a, int n);
void cb_matrice(int **a, int n, int x);
int cb_linie(int *v, int st, int dr, int x);

#endif