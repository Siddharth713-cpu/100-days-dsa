/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    return stack[top--];
}

// Function to define operator precedence
int precedence(char symbol) {
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '+' || symbol == '-') return 1;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, j = 0;

    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        char symbol = infix[i];

        // 1. If character is an operand, add to output
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } 
        // 2. If '(', push to stack
        else if (symbol == '(') {
            push(symbol);
        } 
        // 3. If ')', pop until '(' is found
        else if (symbol == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '('
        } 
        // 4. If operator, handle precedence
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators from stack
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';

    printf("%s\n", postfix);

    return 0;
}
