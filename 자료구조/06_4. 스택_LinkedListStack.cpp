#include <stdio.h>
#include <stdlib.h>
#include "06_4. ����_LinkedListStack.h"

//�ʱ�ȭ �Լ�
void init(LinkedStackType* s) {
	s->top = NULL;
}

//���� ���� ���� �Լ�
int is_empty(LinkedStackType* s) {
	return (s->top == NULL);
}

//��ȭ ���� ���� �Լ�
int is_full(LinkedStackType* s) {
	return 0;
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	if (temp == NULL) {
		fprintf(stderr, "�޸� �Ҵ翡��\n");
		return;
	}
	else {
		temp->item = item;
		temp->link = s->top;
		s->top = temp;
	}
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int item = temp->item;
		s->top = s->top->link;
		free(temp);
		return item;
	}
}

element peek(LinkedStackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		return s->top->item;
	}
}