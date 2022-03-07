#pragma once
#ifndef ArraySTACK
#define ArraySTACK

#define MAX_STACK_SIZE 100
typedef int element;
static element stack[MAX_STACK_SIZE];
static int top = -1;

int is_empty();
int is_full();
void push(element item);
element pop();
element peek();

#endif // !ArraySTACK
