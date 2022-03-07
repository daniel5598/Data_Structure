#include <stdio.h>
#include <stdlib.h>
#include "05_3. 연결리스트(원형, 이중)_PolyLinkedList.h"

void init(ListHeader* plist) {
	plist->length = 0;
	plist->head = plist->tail = NULL;
}

//plist는 연결 리스트의 헤더를 가리키는 포인터, coef는 계수, expon는 지수
void insert_node_last(ListHeader* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) {
		fprintf(stderr, "메모리 할당 에러\n");
		exit(1);
	}
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->length++;
}

void poly_add(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum;
	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0)
				insert_node_last(plist3, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon > b->expon) {
			insert_node_last(plist3, a->coef, a->expon);
			a = a->link;
		}
		else {
			insert_node_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}
	//a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두
	//결과 다항식으로 복사
	for (; a != NULL; a = a->link)
		insert_node_last(plist3, a->coef, a->expon);
	for (; b != NULL; b = b->link)
		insert_node_last(plist3, b->coef, b->expon);
}

void poly_print(ListHeader *plist){
	ListNode* p = plist->head;
	for (; p; p = p->link) {
		printf("%d %d\n", p->coef, p->expon);
	}
}