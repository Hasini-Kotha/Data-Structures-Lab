#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "stack.h"

stack::stack() {
    top = -1;
}

void stack::push(char ch) {
    if (top >= 99) {
        printf("Stack Overflow!\n");
        return;
    }
    arr[++top] = ch;
}

char stack::pop() {
    if (is_empty()) {
        return '\0'; // Nothing to pop
    }
    return arr[top--];
}

int stack::is_empty() {
    return top == -1;
}

void stack::display() {
    for (int i = 0; i <= top; i++) {
        printf("%c", arr[i]);
    }
}

int main() {
    stack s;
    char str[100];
    printf("Enter the string: ");
    scanf("%s", str);

    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        if (str[i] == '+') {
            if (!s.is_empty()) {
                s.pop();  // Remove the last non-'+' symbol
            }
        } else {
            s.push(str[i]);  // Push non-'+' symbol
        }
    }

    printf("Processed string: ");
    s.display();
    printf("\n");
    return 0;
}
