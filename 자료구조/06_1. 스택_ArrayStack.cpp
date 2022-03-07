#include <stdio.h>
#include <stdlib.h>
#include "06_1. ����_ArrayStack.h"

int is_empty() {
	return (top == -1);
}
int is_full() {
	return (top == (MAX_STACK_SIZE - 1));
}
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}
element pop() 
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];
}
element peek()
{
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top];
}