#ifndef HEAP_H
#define HEAP_H

const int DIM_MAX = 100;

void insertHeap(int heap[], int &n, int value);
int removeHeap(int heap[], int &n);
void sortare_aplicatia1(int de_sortat[], int heap[], int n);
void build_heap_v1(int heap[], int &n);
void build_heap_v2(int heap[], int &n);
void retro(int heap[], int &n, int i);
void printHeap(int heap[], int n);

#endif
