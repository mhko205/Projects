#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int pop();
extern void push(int);
extern int heapDelete();
extern void addHeap(int);
extern int heapSize();
extern int buildHeap();
extern int printXML();

int main(int argc, char * argv[])
{
	int temp;
	int val;
	while (scanf("\n%d\n", &val) != EOF) {
		addHeap(val);
	}
	buildHeap();
	printXML(0);
	printf("\n");
	int s = heapSize();
	for(int i = 0; i < s; i++){
		temp = heapDelete();
		printf("%d\n", temp);
		push(temp);
	}
	printf("\n");
	for(int i = 0; i < s; i++){
		printf("%d\n", pop());
	}
	exit(0);
}
