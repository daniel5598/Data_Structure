#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "06_5. ����_BracketArrayStack.h"

int check_matching(char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); //n=���ڿ��� ����
	printf("%d \n", n);
	init(&s); //������ �ʱ�ȭ

	for (i = 0; i < n; i++) {
		ch = in[i]; //ch=���� ����
		switch (ch) {
		case'(': case'[': case'{':
			push(&s, ch);
			break;
		case')': case']': case'}':
			if (is_empty(&s))
				return FALSE;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') ||
					(open_ch == '[' && ch != ']') ||
					(open_ch == '{' && ch != '}')) {
					return FALSE;
				}
				break;
			}
		}
	}

	if (!is_empty(&s))
		return FALSE; //���ÿ� ���������� ����
	return TRUE;
}

int main() {
	if (check_matching("{A[(i+1)]=0;}") == TRUE)
		printf("��ȣ �˻� ����\n");
	else
		printf("��ȣ �˻� ����\n");
}