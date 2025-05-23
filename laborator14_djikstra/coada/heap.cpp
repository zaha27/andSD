#include "heap.h"
#include <iostream>
using namespace std;

void initHeap(Heap& H, int cap) {
    H.data = new Atom[cap];
    H.size = 0;
    H.capacity = cap;
}

int isEmpty(Heap H) {
    return H.size == 0;
}

void swap(Atom& a, Atom& b) {
    Atom t = a;
    a = b;
    b = t;
}

void heapify_up(Heap& H, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (H.data[parent].dist <= H.data[idx].dist) break;
        swap(H.data[parent], H.data[idx]);
        idx = parent;
    }
}

void heapify_down(Heap& H, int idx) {
    while (true) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < H.size && H.data[left].dist < H.data[smallest].dist)
            smallest = left;
        if (right < H.size && H.data[right].dist < H.data[smallest].dist)
            smallest = right;

        if (smallest == idx) break;
        swap(H.data[idx], H.data[smallest]);
        idx = smallest;
    }
}

void push(Heap& H, Atom val) {
    if (H.size == H.capacity) {
        cout << "Heap plin!\n";
        exit(1);
    }
    H.data[H.size] = val;
    heapify_up(H, H.size);
    H.size++;
}

Atom top(Heap H) {
    if (isEmpty(H)) {
        cout << "Heap gol!\n";
        exit(1);
    }
    return H.data[0];
}

void pop(Heap& H) {
    if (isEmpty(H)) {
        cout << "Heap gol!\n";
        exit(1);
    }
    H.data[0] = H.data[--H.size];
    heapify_down(H, 0);
}

void destroyHeap(Heap& H) {
    delete[] H.data;
    H.data = nullptr;
    H.size = H.capacity = 0;
}
