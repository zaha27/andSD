#include <iostream>

struct Node {
    int data;
    Node* succ;
};

typedef Node* Stack;

void push(Stack &head, int value) {
    Stack p = new Node;
    p->data = value;
    p->succ = head;
    head = p;
}

bool isEmpty(const Stack &head) {  
    return (head == nullptr);
}

bool pop(Stack &head) {
    if (!isEmpty(head)) {  
        Stack p = head;  
        head = head->succ;
        delete p;
        return true;
    } else {
        return false;
    }
}

int top(const Stack &head) {
    if(!isEmpty) {
        return false;
    } else {
        return head -> data;
    }
}


