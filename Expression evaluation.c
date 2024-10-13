#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX 100


typedef struct {
    int top;
    char items[MAX];
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Push to stack
void push(Stack *s, char value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

// Pop from stack
char pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Peek at the top of stack
char peek(Stack *s) {if (s->top == -1) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if the character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// Convert infix to postfix
void infixToPostfix(const char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (peek(&s) != '(') {
                postfix[k++] = pop(&s);
            }pop(&s);  // Pop '('
        } else {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c)) {
                postfix[k++] = pop(&s);
            }
            push(&s, c);
        }
    }

    while (s.top != -1) {
        postfix[k++] = pop(&s);
    }
    postfix[k] = '\0';
}

// Reverse expression (used in prefix conversion)
void reverseExpr(char *expr) {
    int len = strlen(expr);
    for (int i = 0; i < len / 2; i++) {
        char temp = expr[i];
        expr[i] = expr[len - i - 1];
        expr[len - i - 1] = temp;
    }
    for (int i = 0; i < len; i++) {
        if (expr[i] == '(') expr[i] = ')';
        else if (expr[i] == ')') expr[i] = '(';
    }
}

// Convert infix to prefix
void infixToPrefix(const char *infix, char *prefix) {
    char revInfix[MAX], revPostfix[MAX];
    strcpy(revInfix, infix); reverseExpr(revInfix);
    infixToPostfix(revInfix, revPostfix);
    reverseExpr(revPostfix);
    strcpy(prefix, revPostfix);
}

// Evaluate postfix expression
int evalPostfix(const char *postfix) {
    Stack s;
    initStack(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(&s, c - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            switch (c) {
                case '+': push(&s, a + b); break;
                case '-': push(&s, a - b); break;
                case '*': push(&s, a * b); break;
                case '/': push(&s, a / b); break;
                case '^': push(&s, pow(a, b)); break;
            }
        }
    }

    return pop(&s);
}


void main(){
    int choice;
    char infix[MAX], expr[MAX];

    do {
        printf("\nMenu:\n");
        printf("1. Infix to Postfix\n2. Infix to Prefix\n3. Evaluate Postfix\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                char postfix[MAX];
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                break;
            case 2:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                char prefix[MAX];
                infixToPrefix(infix, prefix);
                printf("Prefix: %s\n", prefix);
                break;
            case 3:
                printf("Enter postfix expression: ");
                scanf("%s", expr);
                printf("Result: %d\n", evalPostfix(expr));
                break;
            case 4:
                 return;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);    
    
}
