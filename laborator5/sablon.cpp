#include <iostream>

struct Stack {
    int data;
    Stack* succ;
};

void push(Stack *&head, int value) {
    Stack* p = new Stack();
    p->data = value;
    p->succ = head;
    head = p;
}

bool isEmpty(Stack *&head) {  
    return (head == nullptr);
}

bool pop(Stack *&head) {
    if (!isEmpty(head)) {  
        Stack* p = head;  
        head = head->succ;
        delete p;
        return true;
    } else {
        return false;
    }
}


