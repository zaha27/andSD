#include <iostream>
#include "heap.h"
using namespace std;

void insertHeap(int heap[], int &n, int value) {
    heap[++n] = value;
    int fiu = n;
    int parinte = n / 2;
    while(parinte >= 1) {
        if(heap[parinte] < heap[fiu]) {
            swap(heap[parinte], heap[fiu]);
            fiu = parinte;
            parinte /= 2;
        } else {
            parinte = 0;
        }
    }
}

int removeHeap(int heap[], int& n) {
    if(!n) {
        return -1;
    }

    int to_return = heap[1];
    heap[1] = heap[n--];
    int parinte = 1;
    int fiu = 2;

    while(fiu <= n) {
        if((fiu <= n - 1) && (heap[fiu] < heap[fiu + 1])) {
            ++fiu;
        }
        if(heap[fiu] > heap[parinte]) {
            swap(heap[parinte], heap[fiu]);
            parinte = fiu;
            fiu *= 2;
        } else {
            fiu = n + 1;
        }
    }

    return to_return;
}

void printHeap(int heap[], int n) {
    for(int i = 1; i <= n; ++i) {
        cout << heap[i] << ' ';
    }
    cout << '\n';
}