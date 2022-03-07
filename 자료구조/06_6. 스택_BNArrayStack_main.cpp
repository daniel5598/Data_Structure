#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "06_6. 스택_BNArrayStack.h"

#if 0
//중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		//연산자이면
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s)))
				printf("%c", pop(&s));
			push(&s, ch);
		}
		else if (ch == '(')
				push(&s, ch);
		else if (ch == ')') { //오른쪽 괄호
			top_op = pop(&s);
			//왼쪽 괄호를 만날 때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
		}
		else printf("%c", pop(&s));
	}
	while (!is_empty(&s)) //스택에 저장된 연산자들 출력
		printf("%c", pop(&s));
}

#endif
//중위 표기 수식 -> 후위 표기 수식
void infix_to_postfix(char exp[]) {
	int i = 0;
	char ch, top_op;
	int len = strlen(exp);
	StackType s;

	init(&s);
	for (i = 0; i < len; i++) {
		ch = exp[i];
		//연산자이면
		switch (ch) {
		case '+': case'-': case'*': case'/': //연산자
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while (!is_empty(&s) && (prec(ch) <= prec(peek(&s))))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': //왼쪽 괄호
			push(&s, ch);
			break;
		case ')': //오른쪽 괄호
			top_op = pop(&s);
			//왼쪽 괄호를 만날 때까지 출력
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = pop(&s);
			}
			break;
		default: //피연산자
			printf("%c", ch);
			break;
		}
	}

	while (!is_empty(&s)) //스택에 저장된 연산자들 출력
		printf("%c", pop(&s));
}

void main() {
	infix_to_postfix("(2+3)*4+9");
}
