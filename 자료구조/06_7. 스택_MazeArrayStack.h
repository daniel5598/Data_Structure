#pragma once
#ifndef MAZEArraySTACK
#define MAZEArraySTACK

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct StackObjectRec {
	short r;
	short c;
}StackObject;

StackObject stack[MAX_STACK_SIZE];
int top = -1;

void initialize();
int isEmpty();
int isFull();
void push(StackObject item);
StackObject pop();
void printStack();

#endif