#include <iostream>
#include <cctype>
#include "header.h"

using namespace std;

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

char top(const Stack &head) {
    if (isEmpty(head)) {
        cerr << "Eroare: stiva goala" << endl;
        return '\0';
    }
    return head->data;
}

int ordin(char x) {
    if (x == '/' || x == '*') {
        return 2;
    }
    if (x == '+' || x == '-') {
        return 1;
    }
    if (x == '(' || x == ')') {
        return 0;
    }
    return 0; 
}

string to_postfixed(string expresie) {
    Stack stiva = nullptr;
    string rezultat;

    for (int i = 0; i < expresie.length(); ++i) {
        char c = expresie[i];

        if (isdigit(c)) {  
            rezultat.push_back(c);
        } else if(c == '('){
            push(stiva, c);
        } else if(c == ')') {
            while (!isEmpty(stiva) && top(stiva) != '(') {
                rezultat.push_back(top(stiva));
                pop(stiva);
            }
        } else {  
            while (!isEmpty(stiva) && ordin(top(stiva)) >= ordin(c)) {
                rezultat.push_back(top(stiva));
                pop(stiva);
            }
            push(stiva, c);
        }
    }

    while (!isEmpty(stiva)) {
        if(top(stiva) != '(') {
            rezultat.push_back(top(stiva));
        }  
        pop(stiva); 
    }

    return rezultat;
}

int operatie(char op, int t1, int t2) {
    switch(op) {
        case '+': return t1 + t2;
        case '-': return t1 - t2;
        case '*': return t1 * t2;
        case '/': return t1 / t2;
        default:
            cerr << "Operator necunoscut!" << endl;
            exit(1);
    }
}

int result_postfixed(string expresie) {
    int rezultat = 0;
    Stack stiva = nullptr;
    
    for (int i = 0; i < expresie.length(); ++i) {
        char c = expresie[i];

        if (isdigit(c)) {
            push(stiva, c - '0');
        } else if (!isdigit(c)) {  
            int t1 = top(stiva);
            pop(stiva);
            int t2 = top(stiva);
            pop(stiva);
            
            rezultat = operatie(c, t2, t1);  
            push(stiva, rezultat); 
        } else {
            cerr << "Eroare!" << endl;
            exit(1);
        }
    }
    return top(stiva);
}