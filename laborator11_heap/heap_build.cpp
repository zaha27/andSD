#include <iostream>
#include "header.h"

using namespace std;

void build_heap_v1(int heap[], int &n) {
    for(int i = 2; i <= n; ++i) {
        insertHeap(heap, i - 1, heap[i]);
    }
}

void build_heap_v2(int heap[], int &n) {
    for(int i = n / 2; i >= 1; --i) {
        retro(heap, n, i);
    }
}

void retro(int heap[], int &n, int i) {
    int parinte = i;
    int fiu = 2 * i;
    while(fiu <= n) {
        if(fiu + 1 <= n && heap[fiu] < heap[fiu + 1]) {
            fiu++;
        }
        if(heap[fiu] > heap[parinte]) {
            swap(heap[parinte], heap[fiu]);
            parinte = fiu;
            fiu *= 2;
        } else {
            fiu = n + 1;
        }
    }
}
