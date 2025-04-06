#ifndef COADA_H
#define COADA_H

struct Nod {
    int data;
    Nod* next;
};

struct Coada {
    Nod* front;
    Nod* rear;
};

void init(Coada& c);
void enqueue(Coada& c, int val);
void dequeue(Coada& c);
int peek(Coada c);
bool isEmpty(Coada c);
void destroyQueue(Coada& c);

#endif
