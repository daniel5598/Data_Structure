#pragma once
#ifndef ListQueue
#define ListQueue

typedef int element; //����� Ÿ��
typedef struct QueueNode { //ť�� ����� Ÿ��
	element item;
	struct QueueNode* link;
}QueueNode;

typedef struct { //ť ADT ����
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
