#ifndef STACK_SLL_H
#define STACK_SLL_H

#include <cstdio>
#include <cstdlib>

// Node structure
struct Node {
    char data;
    Node* next;
};

// Stack class using SLL
class Stack {
    Node* top;
public:
    Stack() { top = NULL; }
    
    int push(char);
    char pop();
    char peek();
    int is_Empty();
    void display();
};

// Push operation
int Stack::push(char value) {
    Node* newNode = new Node();
    if (!newNode) {
        printf("Heap Overflow\n");
        return 0;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    return 1;
}

// Pop operation
char Stack::pop() {
    if (is_Empty()) {
        printf("Stack Underflow\n");
        return '\0';
    }
    char value = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return value;
}

// Peek operation
char Stack::peek() {
    if (!is_Empty()) return top->data;
    return '\0';
}

// Check if stack is empty
int Stack::is_Empty() {
    return top == NULL;
}

// Display stack elements
void Stack::display() {
    if (is_Empty()) {
        printf("Stack is Empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack Elements: ");
    while (temp) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

#endif 
