#include <stdio.h>
#include <stdlib.h>
#include "05_2. 연결리스트(원형, 이중)_DLinkedList.h"

void main() {
	DlistNode head_node;
	DlistNode* p[10];
	int i;

	init(&head_node);
	for (i = 0; i < 5; i++) {
		p[i] = (DlistNode*)malloc(sizeof(DlistNode));
		p[i]->data = i;
		//헤드 노드의 오른쪽에 삽입
		dinsert_node(&head_node, p[i]);
	}
	dremove_node(&head_node, p[4]);
	display(&head_node);
}