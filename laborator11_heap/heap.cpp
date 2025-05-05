#include <iostream>
#include "heap.h"
using namespace std;

void insertHeap(int heap[100], int &n, int value) {
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
        exit(1);
    } else {
        int to_return = heap[1];
        heap[1] = heap[n--];
        int parinte = 1;
        int fiu = 2;
        while(fiu < n) {
            if( (fiu <= n - 1) && (heap[fiu] < heap[fiu + 1]) ) {
                ++fiu;
            } else if(heap[fiu] > heap[parinte]) {
                swap(heap[parinte], heap[fiu]);
                parinte = fiu;
                fiu *= 2;
            } else {
                fiu = n + 1;
            }
        }
    }
    return to_return;
}



int removeHeap(int heap[], int& n) {
    if (n == 0) {
        cout << "Heap gol!\n";
        return -1;
    }
    int maxVal = heap[1];
    heap[1] = heap[n];
    n--;

    int i = 1;
    while (2 * i <= n) {
        int fiu = 2 * i;
        if (fiu + 1 <= n && heap[fiu + 1] > heap[fiu])
            fiu++;
        if (heap[i] < heap[fiu]) {
            swap(heap[i], heap[fiu]);
            i = fiu;
        } else {
            break;
        }
    }
    return maxVal;
}

