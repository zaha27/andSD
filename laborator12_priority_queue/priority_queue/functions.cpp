#include "header.h"
#include <iostream>
using namespace std;

void initQueue(Queue& Q) {
    Q.head = Q.tail = nullptr;
}

int isEmpty(Queue Q) {
    return Q.head == nullptr && Q.tail == nullptr;
}

void put(Queue& Q, Atom a) {
    Element* temp = new Element;
    temp->data = a;
    temp->succ = nullptr;

    if (!isEmpty(Q)) {
        if (a > Q.head->data) { //a e cek mai mare 
            temp->succ = Q.head;
            Q.head = temp;
            return;
        }
        //altfel
        Element* p = Q.head;
        for(; p != Q.tail && p->succ->data >= a; p = p->succ)
            ;

        temp->succ = p->succ;
        p->succ = temp;

    } else {
        Q.head = Q.tail = temp;
    }
}

Atom get(Queue& Q) {
    if (isEmpty(Q)) {
        cout << "coada este goala";
        exit(1);
    }

    Atom val = Q.head->data;
    Element* temp = Q.head;
    Q.head = Q.head->succ;
    delete temp;

    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }

    return val;
}

Atom front(Queue Q) {
    if (isEmpty(Q)) {
        cout << "coada este goala";
        exit(1);
    }
    return Q.head->data;
}
