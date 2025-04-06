#ifndef STIVA_H
#define STIVA_H

struct Nod {
    int data;
    Nod* next;
};

typedef Nod* Stack;

void push(Stack& s, int val);
void pop(Stack& s);
int peek(Stack s);
bool isEmpty(Stack s);
void destroyStack(Stack& s);

#endif
