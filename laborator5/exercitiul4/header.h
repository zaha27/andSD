#ifndef HEADER_H_
#define HEADER_H_

#include <string>
using namespace std;

struct Node {
    char data;
    Node* succ;
};

typedef Node* Stack;

void push(Stack &head, int value);
bool isEmpty(const Stack &head);
bool pop(Stack &head);
char top(const Stack &head);
int operatie(char op, int t1, int t2);
string to_prefixed(string expresie);
int result_prefixed(string expresie);

#endif
