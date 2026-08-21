#include <stdio.h>
#include <stdlib.h>

static int top = -1;
static int stack[1000];
/**
 * pop() removes the top integer on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value -1 (minus one) is returned.
 */
int pop()
{
	if(top == -1){
		printf("Stack underflow");
		exit(1);
	} 
	
	return(stack[top--]);
}

/**
 *  push(thing2push) adds the "thing2push" to the top of the stack.
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(int thing2push)
{
	if(top==99){
		printf("Stack overflow");
	}
	top++;
	stack[top] = thing2push;
}

/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty()
{
	return top == -1;
}
