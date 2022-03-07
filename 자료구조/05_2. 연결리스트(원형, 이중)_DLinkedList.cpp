#include <stdio.h>
#include <stdlib.h>
#include "05_2. 연결리스트(원형, 이중)_DLinkedList.h"

void init(DlistNode* phead) {

	phead->llink = phead;
	phead->rlink = phead;
}
void display(DlistNode* phead) {
	DlistNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf("<---| %x | %d | %x | --->\n", p->llink, p->data, p->rlink);
	}
	printf("\n");
}

//노드 new_node를 노드 before의 오른쪽에 삽입한다.
void dinsert_node(DlistNode* before, DlistNode* new_node) {
	new_node->llink = before;
	new_node->rlink = before->rlink;
	before->rlink->llink = new_node;
	before->rlink = new_node;
}
void dremove_node(DlistNode* phead_node, DlistNode* removed) {
	if (removed == phead_node)return;
	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}