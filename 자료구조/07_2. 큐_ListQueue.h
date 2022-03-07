#pragma once
#ifndef ListQueue
#define ListQueue

typedef int element; //요소의 타입
typedef struct QueueNode { //큐의 노드의 타입
	element item;
	struct QueueNode* link;
}QueueNode;

typedef struct { //큐 ADT 구현
	QueueNode* front, * rear;
}QueueType;

void error(char* message);
void init(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
element peek(QueueType* q);

#endif // !ListQueue
