#pragma once
#ifndef LinkedListSTACK
#define LinkedListSTACK

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef int element;

typedef struct StackNode {
	element item;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s);
int is_empty(LinkedStackType* s);
int is_full(LinkedStackType* s);
void push(LinkedStackType* s, element item);
element pop(LinkedStackType* s);
element peek(LinkedStackType* s);

#endif