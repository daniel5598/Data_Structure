#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "06_2. 스택_StudArrayStack_전역변수.h"

void main()
{
	element ie, oe;
	int cho;
	while (1)
	{
		printf("1.push 2.pop 3.peek 4.종료: ");
		scanf("%d", &cho);
		if (cho == 1) {
			printf("번호 이름 주소: ");
			scanf("%d %s %s", &ie.student_no, &ie.name, &ie.address);
			push(ie);
		}
		if (cho == 2) {
			oe = pop();
			printf("name: %s\n", oe.name);
			printf("address: %s\n", oe.address);
			printf("student number: %d\n", oe.student_no);
		}
		if (cho == 3) {
			oe = peek();
			printf("name: %s\n", oe.name);
			printf("address: %s\n", oe.address);
			printf("student number: %d\n", oe.student_no);
		}
		if (cho == 4) break;
	}
}