#ifndef HEAP_H_
#define HEAP_H_

struct Atom {
    int nod;
    unsigned int dist;
};

struct Heap {
    Atom* data;
    int size;
    int capacity;
};

void initHeap(Heap& H, int cap);
void push(Heap& H, Atom val);
Atom top(Heap H);
void pop(Heap& H);
int isEmpty(Heap H);
void destroyHeap(Heap& H);

#endif
