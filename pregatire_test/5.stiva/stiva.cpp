#include <iostream>
#include "stiva.h"

using namespace std;

void push(Stack& s, int val) {
    Nod* temp = new Nod;
    if(s == nullptr) {
        temp->data = val;
        temp->next = nullptr;
        s = temp;
        return ;
    }
    temp->next = s;
    s = temp;
}

void pop(Stack& s) {
    if(s == nullptr) {
        cerr << "Stiva este goala";
        exit(1);
    }
    Nod *temp = s;
    s = s->next;
    delete temp;
}

int peek(Stack s) {
    if(s == nullptr) {
        cerr << "Stiva este goala";
        exit(1);
    }

    return s->data;
}

bool isEmpty(Stack s) {
    return s == nullptr;
}

void destroyStack(Stack& s) {
    Nod* p = s;
    while (p != nullptr) {
        Nod* temp = p;
        p = p->next;
        delete temp;
    }

    s = nullptr; 
}
