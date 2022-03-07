#include <stdio.h>
#include <stdlib.h>
#include "04_2. 리스트(연결리스트기반)_Point.h"
#include "04_2. 리스트(연결리스트기반)_Point_LinkedList.h"

//phead: 리스트의 헤드 포인터의 포인터
//p: 선행 노드
//new_node: 삽입될 노드
void insert_node(ListNode** phead, ListNode* new_node) { //입력
	ListNode* ap;
	ap = *phead;
	if (*phead == NULL) { //공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else {
		while (1) {
			if (ap->link == NULL) break;
			ap = ap->link;
		}
		ap->link = new_node;
	}
}

void display(ListNode* head) { //출력
	ListNode* p = head;
	while (p != NULL) {
		printf("%3d %10s %3.0f\n", p->data.no, p->data.name, p->data.score);
		p = p->link;
	}
	printf("\n");
}

//노드를 동적으로 생성하는 프로그램
ListNode* create_node(Point data, ListNode* link) { //생성
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