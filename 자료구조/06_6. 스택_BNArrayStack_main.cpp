#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "06_6. ����_BNArrayStack.h"

#if 0
//���� ǥ�� ���� -> ���� ǥ�� ����
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		//�������̸�
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))
				printf("%c", pop(&s));
			push(&s, ch);
		}
		else if (ch == '(')
				push(&s, ch);
		else if (ch == ')') { //������ ��ȣ
			top_op = pop(&s);
			//���� ��ȣ�� ���� ������ ���
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
		}
		else printf("%c", pop(&s));
	}
	while (!is_empty(&s)) //���ÿ� ����� �����ڵ� ���
		printf("%c", pop(&s));
}

#endif
//���� ǥ�� ���� -> ���� ǥ�� ����
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		//�������̸�
		switch (ch) {
		case '+': case'-': case'*': case'/': //������
			//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': //���� ��ȣ
			push(&s, ch);
			break;
		case ')': //������ ��ȣ
			top_op = pop(&s);
			//���� ��ȣ�� ���� ������ ���
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: //�ǿ�����
			printf("%c", ch);
			break;
		}
	}

	while (!is_empty(&s)) //���ÿ� ����� �����ڵ� ���
		printf("%c", pop(&s));
}

void main() {
	infix_to_postfix("(2+3)*4+9");
}
