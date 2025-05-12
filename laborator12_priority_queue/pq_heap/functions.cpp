#include "header.h"
#include <iostream>
using namespace std;

void initHeap(Heap& h) {
    h.n = 0;
}

void printHeap(Heap h) {
    for (int i = 0; i < h.n; i++) {
        cout << h.v[i] << " ";
    }
    cout << endl;
}

void insertHeap(Heap& h, int val) {
    if (h.n == DIM_MAX) {
        cout << "Heap plin!\n";
        return;
    }

    int i = h.n;
    h.v[i] = val;
    h.n++;

    while (i > 0 && h.v[(i - 1) / 2] < h.v[i]) {
        swap(h.v[i], h.v[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int topMax(Heap h) {
    if (h.n == 0) {
        cout << "Heap gol!\n";
        exit(1);
    }
    return h.v[0];
}

void heapifyDown(Heap& h, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < h.n && h.v[left] > h.v[largest])
        largest = left;

    if (right < h.n && h.v[right] > h.v[largest])
        largest = right;

    if (largest != i) {
        swap(h.v[i], h.v[largest]);
        heapifyDown(h, largest);
    }
}

int extractMax(Heap& h) {
    if (h.n == 0) {
        cout << "Heap gol!\n";
        exit(1);
    }

    int val = h.v[0];
    h.v[0] = h.v[h.n - 1];
    h.n--;
    retro(h, 0);
    return val;
}