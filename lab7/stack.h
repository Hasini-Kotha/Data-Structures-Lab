#ifndef STACK_H
#define STACK_H

class stack {
    char arr[100];
    int top;
public:
    stack();
    void push(char);
    char pop();
    int is_empty();
    void display();
};

#endif
