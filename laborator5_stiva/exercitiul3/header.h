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
string to_postfixed(string expresie);
int result_postfixed(string expresie);

#endif
