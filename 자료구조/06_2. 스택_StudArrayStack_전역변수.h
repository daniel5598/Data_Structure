#pragma once
#ifndef StudArraySTACK
#define StudArraySTACK

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element;

static element stack[MAX_STACK_SIZE];
static int top = -1;

int is_empty();
int is_full();
void push(element item);
element pop();
element peek();

#endif
