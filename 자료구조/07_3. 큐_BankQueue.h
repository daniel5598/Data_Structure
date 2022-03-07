#pragma once
#ifndef QUEUE
#define QUEUE
#define TRUE 1
#define FALSE 0
#define MAX_QUEUE_SIZE 100

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;

typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

static QueueType queue;

void init(QueueType* q);
int is_empty(QueueType* q);
int is_full(QueueType* q);
void enqueue(QueueType* q, element item);
element dequeue(QueueType* q);
#endif