#include "header.h"
#include <iostream>

using namespace std;

int NextPos(int index) {
    if (index < DIMMAX - 1) {
        return index + 1;
    } else {
        return 0;
    }
}

void initQueue(Queue& Q) {
    Q.head = Q.tail = 0;
}

int isEmpty(const Queue& Q) {
    return Q.head == Q.tail;
}

int isFull(const Queue& Q) {
    return NextPos(Q.tail) == Q.head;
}

void put(Queue& Q, Atom a) {
    if (isFull(Q)) { 
        cout << "coada este plina";
        exit(1);
    }
    Q.vect[Q.tail] = a;
    Q.tail = NextPos(Q.tail);
}

Atom get(Queue& Q) {
    if (isEmpty(Q)) {
        cout << "coada este goala";
        exit(1);
    }
    Atom val = Q.vect[Q.head];
    Q.head = NextPos(Q.head);
    return val;
}

Atom front(const Queue& Q) {
    if (isEmpty(Q)) {
        cout << "coada este goala";
        exit(1);
    }
    return Q.vect[Q.head];
}
