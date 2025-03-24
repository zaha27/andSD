#ifndef HEADER_H_
#define HEADER_H_


#define DIMMAX 8
typedef int Atom;

struct Queue {
    int head,tail;
    Atom vect[DIMMAX];
};
void initQueue(Queue& Q);
void put(Queue& Q, Atom a);
Atom get(Queue& Q);
Atom front(const Queue& Q); 
int isEmpty(const Queue& Q); 
int isFull(const Queue& Q);

#endif