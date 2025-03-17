#include <iostream>

using namespace std;

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
        cerr << "Eroare: stiva goala" << endl;
    }
    
    return head -> data;
    
}


int main() {
    Stack s = nullptr;

    push(s, 10);
    push(s, 20);
    push(s, 30);
    
    cout << "varf: " << top(s) << endl;

    pop(s);
    cout << "varf dupa pop: " << top(s) << endl;

    while (!isEmpty(s)) {
        pop(s);
    }

    cout << "stiva goala (Da/Nu):  " << (isEmpty(s) ? "Da" : "Nu") << endl;

    return 0;
}
