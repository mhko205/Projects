#include <stdio.h>

// Static global variables
static int top = 0;
static char* stack[100];
/**
 * pop() removes the top string on the stack and returns it.
 *
 * If pop() is attempted on an empty stack, an error message
 * is printed to stderr and the value NULL ((char *) 0) is returned.
 */
char* pop() {
    if (top == 0) {
        fprintf(stderr, "Error: stack is empty\n");
        return (char*)0;
    }
    else {
        top--;
        return stack[top];
    }
}
/**
 *
 *  If there is no more space available on the Stack, an error
 *  message is printed to stderr.
 */
void push(char* object) {
    if (top == 100) {
        fprintf(stderr, "Error: stack is full\n");
    }
    else {
        stack[top] = object;
        top++;
    }
}
/**
 * isEmpty() returns a non-zero integer (not necessarily 1) if the
 * stack is empty; otherwise, it returns 0 (zero).
 *
 */
int isEmpty() {
    return (top == 0);
}
