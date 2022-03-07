#include<stdio.h>
#include<stdlib.h>
#include"04_3. 리스트(연결리스트기반)_LinkedList.h"

//phead: 리스트의 헤드 포인터의 포인터
//p: 선행 노드
//new_node: 삽입될 노드

//입력
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) { //공백리스트인 경우
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { //p가 NULL이면 첫번째 노드로 삽입
		new_node->link = *phead;
		*phead = new_node;
	}
	else { //p 다음에 삽입
		new_node->link = p->link;
		p->link = new_node;
	}
}

//생성
ListNode* create_node(int data, ListNode* link) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		printf("메모리 할당 에러\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;
	printf("완료\n");
	return(new_node);
}

//출력
void display(ListNode* head) {
	ListNode* p = head;
	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n\n");
}

void display_recur(ListNode* head) {
	ListNode* p = head;
	if (p != NULL) {
		printf("%d->", p->data);
		display_recur(p->link);
	}
}

//삭제
void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

//검색
ListNode* search(ListNode* head, int x) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x)return p; //탐색 성공
		p = p->link;
	}
	return p; // 탐색 실패일 경우 NULL 반환
}

//연결
ListNode* concat(ListNode* head1, ListNode* head2) {
	ListNode* p;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

//역순
ListNode* reverse(ListNode* head) {
	//순회 포인터로 p,q,r을 사용
	ListNode* p, * q, * r;
	p = head; //p는 역순으로 만들 리스트
	q = NULL; //q는 역순으로 만들 노드
	while (p != NULL) {
		r = q; //r은 역순으로 된 리스트, r은 q, q는 p를 차례로 따라간다.
		q = p;
		p = p->link;
		q->link = r; //q의 링크 방향을 바꾼다.
	}
	return q; //q는 역순으로 된 리스트의 헤드 포인터
}


