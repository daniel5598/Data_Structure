#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "06_7. ½ºÅÃ_MazeArrayStack.h"

void initialize() {
	top = -1;
}

int isEmpty() {
	return(top == -1);
}

int isFull() {
	return(top == (MAX_STACK_SIZE - 1));
}

void push(StackObject item) {
	if (isFull()) {
		printf("stack is full\n");
	}
	else stack[++top] = item;
}

StackObject pop() {
	if (isEmpty()) {
		printf("stack is empty\n");
	}
	else
		return stack[top--];
}

void printStack() {
	int i;
	for (i = 5; i > top; i--)
		printf("|    |\n");
	for (i = top; i >= 0; i--)
		printf("|(%01d,%01d)|\n", stack[i].r, stack[i].c);
	printf("-------\n");
}
