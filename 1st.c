#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#define STACK_MAX_SIZE 20
char stack [STACK_MAX_SIZE];

int top = -1;

//Return 1 if stack is empty else return 0.
int isEmpty() {
return top == -1;
}

//Push the character into stack
void push(char x) {
   if (top == STACK_MAX_SIZE -1) {
   printf("Stack Overflow\n");
   exit(1);
}
    stack[++top] = x;
}

//pop a character from stack
char pop() {
   if (isEmpty()) {
   //stack underflow shoudn't occur if expression is valid
   return '\0';
}
   return stack[top--]; 
}

	// Return 0 if char is '('
// Return 1 if char is '+' or '-'
// Return 2 if char is '*' or '/' or '%'
int priority(char x) {
   if (x == '(') return 0;
   if (x == '+' || x == '-') return 1;
   if (x == '*' || x == '/' || x == '%') return 2;
   return -1;
}


//Output Format
//if expression is correct then output will be Postfix Expression : <postfix notation>
//If expression contains invalid operators then output will be "Invalid symbols in infix expression. Only alphanumberic and { '+', '-','*', '%%', '/' } are allowed."
//If the expression contains unbalanced paranthesis the output will be "Invalid infix expression : unbalanced parenthesis."
void convertInfix(char * e) {
   char postfix[100];
   int k =0;
   int len = strlen(e);
   int balance = 0;

   //Validate expression and convert
   for (int i = 0; i < len; i++) {
   char c = e[i];

	   // Check allowed characters
	   if (!(isalnum(c) || c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')')) {
   printf("Invalid symbols\n");
		   return;
	   }

   if (isalnum(c)) {
	   postfix[k++] = c;
   }
	   else if (c == '(') {
		   push(c);
		   balance++;
	   }
	   else if (c == ')') {
		   balance--;
		   if (balance < 0) {
			   printf("Unbalanced parenthesis\n");
		   return;
	   }
	   while (!isEmpty() && stack[top] != '(') {
		   postfix[k++] = pop();
	   }
	   if (!isEmpty() && stack[top] == '(') {
		   pop(); 
} //2nd time
   }
else { // Operator encountered
	while (!isEmpty() && priority(stack[top]) >= priority(c)) {
		    postfix[k++]= pop();
	}
	push(c);
}
}

   if (balance != 0) {
	   printf("Unbalanced parenthesis\n");
	   return;
   }

   // Pop remaining operators
while (!isEmpty()) {
	if (stack[top] == '(') {
		printf("Unbalanced parenthesis.\n");
		return;
	}
	postfix[k++] = pop();
}

   postfix[k++] = '\0';

printf("%s\n", postfix);
}