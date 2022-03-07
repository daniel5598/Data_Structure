#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "07_3. ť_BankQueue.h"

//�ʱ�ȭ �Լ�
void init(QueueType* q) {
	q->front = q->rear = 0;
}

//���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "ť�� ��ȭ�����Դϴ�.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "ť�� ��������Դϴ�.\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}  