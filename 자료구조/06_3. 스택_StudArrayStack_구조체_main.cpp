#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "06_3. ����_StudArrayStack_����ü.h"

void main()
{
	StackType s;
	element ie, oe;
	int cho;
	init(&s);
	while (1)
	{
		printf("1.push 2.pop 3.peek 4.����: ");
		scanf("%d", &cho);
		if (cho == 1) {
			printf("��ȣ �̸� �ּ� :");
			scanf("%d %s %s", &ie.student_no, ie.name, ie.address);
			push(&s, ie);
		}
		if (cho == 2) {
			oe = pop(&s);
			printf("name: %s\n", oe.name);
			printf("address: %s\n", oe.address);
			printf("student number: %d\n", oe.student_no);
		}
		if (cho == 3) {
			oe = peek(&s);
			printf("name: %s\n", oe.name);
			printf("address: %s\n", oe.address);
			printf("student number: %d\n", oe.student_no);
		}
		if (cho == 4) break;
	}
}