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
    if(!isEmpty(head)) {
        std::cerr << "Eroare: stiva goala" << std::endl;
    } else {
        return head -> data;
    }
}


int main() {
    Stack s = nullptr;

    push(s, 10);
    push(s, 20);
    push(s, 30);

    std::cout << "varf: " << top(s) << std::endl;

    pop(s);
    std::cout << "varf dupa pop: " << top(s) << std::endl;

    while (!isEmpty(s)) {
        pop(s);
    }

    std::cout << "stiva goala (Da/Nu):  " << (isEmpty(s) ? "Da" : "Nu") << std::endl;

    return 0;
}
