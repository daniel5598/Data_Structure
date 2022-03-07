#include <stdio.h>
#include <stdlib.h>
#include "05_1. 연결리스트(원형, 이중)_LinkedList.h"

ListNode* create_node(element data, ListNode* link) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;
	return(new_node);
}

//phead: 리스트의 헤드 포인터의 포인터
//p: 선행 노드
//node: 삽입될 노드
void insert_first(ListNode** phead, ListNode* node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
	}
}

//phead: 리스트의 헤드 포인터의 포인터
//p: 선행 노드
//node: 삽입될 노드
void insert_last(ListNode** phead, ListNode* node) {
	if (*phead == NULL) {
		*phead = node;
		node->link = node;
	}
	else {
		node->link = (*phead)->link;
		(*phead)->link = node;
		*phead = node;
	}
}

void display(ListNode* head) {
	ListNode* p;
	if (head == NULL)return;

	p = head;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
}