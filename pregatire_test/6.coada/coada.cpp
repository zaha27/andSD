#include <iostream>
#include "coada.h"



void init(Coada& c) {
    c->front = c->rear = nullptr;
}
void enqueue(Coada& c, int val) {
    
    Nod* temp = new Nod;
    temp->next = nullptr;

    if(!isEmpty(c)) {
        c->front = temp;
        c->rear = temp;
        return;    
    }
    rear->next = temp;
}
void dequeue(Coada& c) {
    Nod* temp;
    if(!isEmpty(c))
}
int peek(Coada c) {

}
bool isEmpty(Coada c) {

}
void destroyQueue(Coada& c){

}

