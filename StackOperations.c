#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack Structure
int stack[MAX];
int top = -1;

void push(int value) {
    if (top == MAX - 1) printf("Stack Overflow\n");
    else stack[++top] = value;
}

int pop() {
    if (top == -1) { printf("Stack Underflow\n"); return -1; }
    else return stack[top--];
}

void peek() {
    if (top == -1) printf("Stack is empty\n");
    else printf("Top element: %d\n", stack[top]);
}

// Precedence helper for Infix to Postfix
int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

void infixToPostfix(char* infix) {
    char postfix[MAX];
    int p = 0;
    for (int i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) postfix[p++] = infix[i];
        else if (infix[i] == '(') push('(');
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(') postfix[p++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[p++] = pop();
            push(infix[i]);
        }
    }
    while (top != -1) postfix[p++] = pop();
    postfix[p] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main() {
    // Example usage
    push(10);
    push(20);
    peek();
    pop();
    infixToPostfix("a+b*c");
    return 0;
}