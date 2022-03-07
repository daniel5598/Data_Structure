#include <stdio.h>
#include <stdlib.h>
#include "06_1. 스택_ArrayStack.h"

int is_empty() {
	return (top == -1);
}
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}
element pop() 
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}