#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define STACK_MAX_SIZE 100

int stack[STACK_MAX_SIZE];
int top = -1;

int isEmpty() {
return top == -1;
}

void push(int value) {
if(top >= STACK_MAX_SIZE - 1) {
printf("Stack overflow\n");
exit(1);
}
stack[++top] = value;
}

int pop() {
if(isEmpty()) {
printf("Invalid postfix expression\n");
exit(1);
}
return stack[top--];
}

int isOperator(char ch) {
return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void evaluatePostfix(char expr[]) {
int i = 0;
while(expr[i] != '\0') {
char ch = expr[i];
if(isdigit(ch)) {
push(ch - '0');
}
else if(isOperator(ch)) {
if(top < 1) {
printf("Invalid postfix expression\n");
return;
}
int operand2 = pop();
int operand1 = pop();
int result;
switch(ch) {
case '+': result = operand1 + operand2; break;
case '-': result = operand1 - operand2; break;
case '*': result = operand1 * operand2; break;
case '/':
if(operand2 == 0) {
printf("Division by zero\n");
return;
}
result = operand1 / operand2; break;
}
push(result);
}
else if(ch != ' ') {
printf("Invalid postfix expression\n");
return;
}
i++;
}
if(top == 0) {
printf("%d\n", pop());
} else {
printf("Invalid postfix expression\n");
}
}

int main() {
char expr[100];
fgets(expr, sizeof(expr), stdin);
expr[strcspn(expr, "\n")] = '\0';
evaluatePostfix(expr);
return 0;
}
