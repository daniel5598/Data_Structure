#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "07_3. 큐_BankQueue.h"

//초기화 함수
void init(QueueType* q) {
	q->front = q->rear = 0;
}

//공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

//포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

//삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "큐가 포화상태입니다.\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

//삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		fprintf(stderr, "큐가 공백상태입니다.\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}  