#include <stdio.h>
#include <stdlib.h>
#include "07_1. ť_CircularQueue.h"

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//�ʱ�ȭ �Լ�
void init(QueueType* q) {
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return(q->front == q->rear);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}
