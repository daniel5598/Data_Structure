#include <stdio.h>
#include <stdlib.h>
#include "04_2. ����Ʈ(���Ḯ��Ʈ���)_Point.h"
#include "04_2. ����Ʈ(���Ḯ��Ʈ���)_Point_LinkedList.h"

//phead: ����Ʈ�� ��� �������� ������
//p: ���� ���
//new_node: ���Ե� ���
void insert_node(ListNode** phead, ListNode* new_node) { //�Է�
	ListNode* ap;
	ap = *phead;
	if (*phead == NULL) { //���鸮��Ʈ�� ���
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

void display(ListNode* head) { //���
	ListNode* p = head;
	while (p != NULL) {
		printf("%3d %10s %3.0f\n", p->data.no, p->data.name, p->data.score);
		p = p->link;
	}
	printf("\n");
}

//��带 �������� �����ϴ� ���α׷�
ListNode* create_node(Point data, ListNode* link) { //����
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ����\n");
		exit(1);
	}

	new_node->data = data;
	new_node->link = link;
	return(new_node);
}