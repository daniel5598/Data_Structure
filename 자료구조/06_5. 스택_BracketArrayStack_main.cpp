#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "06_5. 스택_BracketArrayStack.h"

int check_matching(char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); //n=문자열의 길이
	printf("%d \n", n);
	init(&s); //스택의 초기화

	for (i = 0; i < n; i++) {
		ch = in[i]; //ch=다음 문자
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
		return FALSE; //스택에 남아있으면 오류
	return TRUE;
}

int main() {
	if (check_matching("{A[(i+1)]=0;}") == TRUE)
		printf("괄호 검사 성공\n");
	else
		printf("괄호 검사 실패\n");
}