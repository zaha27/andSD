#ifndef HEADER_H_
#define HEADER_H_

#define DIM_MAX 100

struct Heap {
    int v[DIM_MAX];
    int n;
};

void initHeap(Heap& h);
void insertHeap(Heap& h, int val);
int topMax(Heap h);
int extractMax(Heap& h);
void heapifyDown(Heap& h, int i);
void printHeap(Heap h);



#endif