#ifndef HEADER_H_
#define HEADER_H_

typedef int Atom;

struct Element{
    Atom data;
    Element* succ;
};
    struct Queue {
    Element *head, *tail;
};
void initQueue(Queue& Q);
void put(Queue& Q, Atom a);
Atom get(Queue& Q);
Atom front(Queue Q);
int isEmpty(Queue Q);

#endif