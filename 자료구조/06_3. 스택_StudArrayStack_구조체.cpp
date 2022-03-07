#include <stdio.h>
#include <stdlib.h>
#include "06_3. ����_StudArrayStack_����ü.h"

void init(StackType* s) {
	s->top = -1;
}

//���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

//���� �Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else 
		s->stack[++(s->top)] = item;
}

//���� �Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->stack[(s->top)--];
}

//��ũ �Լ�
element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->stack[(s->top)];
}