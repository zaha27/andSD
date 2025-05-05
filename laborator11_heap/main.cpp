#include <iostream>
#include "heap.h"
using namespace std;

int main() {
    int heap[DIM_MAX];
    int n = 0;

    insertHeap(heap, n, 20);
    insertHeap(heap, n, 35);
    insertHeap(heap, n, 10);
    insertHeap(heap, n, 50);
    insertHeap(heap, n, 15);

    printHeap(heap, n);
    removeHeap(heap, n);
    printHeap(heap, n);

    int de_sortat[] = [5, 4, 3, 1, 2, 6, 7];
    n = 7;
    sortare_aplicatia1(de_sortat, heap, n);
    printHeap(heap, n);

    return 0;
}
