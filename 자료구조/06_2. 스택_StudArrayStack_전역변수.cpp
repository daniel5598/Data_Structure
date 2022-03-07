#include <stdio.h>
#include <stdlib.h>
#include "06_2. ����_StudArrayStack_��������.h"

//���� ���� ���� �Լ�
int is_empty()
{
	return (top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full()
{
	return (top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(element item)
{
	if (is_full()) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;
}

//���� �Լ�
element pop() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
		return stack[top--];
}

//��ũ �Լ�
element peek() {
	if (is_empty()) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return stack[top];
}