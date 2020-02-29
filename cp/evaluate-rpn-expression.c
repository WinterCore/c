#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

#define STACK_SIZE 2

double calculate(const double *a, const double *b, const char *op) {
    switch (*op) {
    case '+':
        return *a + *b;
    case '-':
        return *a - *b;
    case '*':
        return *a * *b;
    case '/':
        return *a / *b;
    }
    return 0;
}

double evaluate_RPN_expression(const char *expression) {
    double operands[STACK_SIZE];
    double *operand = operands;
    const char *p   = expression;
    while (*expression) {
        if (*expression == ' ' || *expression == '\n') {
            if (*p == '+' || *p == '-' || *p == '*' || *p == '/') {
                if (operand - 2 < operands) {
                    printf("Not enough operands in expression, operator: %c", *p);
                    exit(SIGTERM);
                }
                double result = calculate(operand - 2, operand - 1, p);
                operand = operand - 2;
                *operand++ = result;
            } else {
                if (operand >= &operands[STACK_SIZE]) {
                    printf("Expression is too complex");
                    exit(SIGTERM);
                }
                sscanf(p, "%lf", operand++);
            }
            p = expression + 1;
        }
        expression++;
    }
    if (operand != (operands + 1)) {
        printf("Expression couldn't be resolved, insufficient operators");
        exit(SIGTERM);
    }
    return operands[0];
}

int main(int argc, char *argv[]) {
    char temp[100];
    printf("Enter an expression: ");
    fgets(temp, 100, stdin);
    printf("%f", evaluate_RPN_expression(temp));

    return 0;
}

