#include <stdio.h>
#include <stdlib.h>
#include "07_1. 큐_CircularQueue.h"

void main() {
	QueueType q;
	init(&q);
	int cho, num;
	printf("front=%d rear=%d\n", q.front, q.rear);

	while (1) {
		printf("1.enqueue 2.dequeue 3.종료: ");
		scanf("%d", &cho);
		if (cho == 1) {
			printf("정수입력: ");
			scanf("%d", &num);
			enqueue(&q, num);
			printf("front=%d rear=%d\n", q.front, q.rear);
		}
		if (cho == 2) {
			printf("dequeue()=%d\n", dequeue(&q));
			printf("front=%d rear=%d\n", q.front, q.rear);
		}
		if (cho == 3)
			break;
	}
}