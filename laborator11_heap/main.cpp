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

    cout << "Heap-ul dupa inserari: ";
    printHeap(heap, n);

    cout << "Element scos: " << removeHeap(heap, n) << "\n";
    cout << "Heap-ul dupa stergere: ";
    printHeap(heap, n);

    // Heap sort
    heapSort(heap, n);

    return 0;
}
