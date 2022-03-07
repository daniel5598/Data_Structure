#include<stdio.h>
#include<stdlib.h>
#include"04_3. ����Ʈ(���Ḯ��Ʈ���)_LinkedList.h"

//phead: ����Ʈ�� ��� �������� ������
//p: ���� ���
//new_node: ���Ե� ���

//�Է�
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node) {
	if (*phead == NULL) { //���鸮��Ʈ�� ���
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { //p�� NULL�̸� ù��° ���� ����
		new_node->link = *phead;
		*phead = new_node;
	}
	else { //p ������ ����
		new_node->link = p->link;
		p->link = new_node;
	}
}

//����
ListNode* create_node(int data, ListNode* link) {
	ListNode* new_node;
	new_node = (ListNode*)malloc(sizeof(ListNode));
	if (new_node == NULL) {
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}
	new_node->data = data;
	new_node->link = link;
	printf("�Ϸ�\n");
	return(new_node);
}

//���
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

//����
void remove_node(ListNode** phead, ListNode* p, ListNode* removed) {
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

//�˻�
ListNode* search(ListNode* head, int x) {
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x)return p; //Ž�� ����
		p = p->link;
	}
	return p; // Ž�� ������ ��� NULL ��ȯ
}

//����
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

//����
ListNode* reverse(ListNode* head) {
	//��ȸ �����ͷ� p,q,r�� ���
	ListNode* p, * q, * r;
	p = head; //p�� �������� ���� ����Ʈ
	q = NULL; //q�� �������� ���� ���
	while (p != NULL) {
		r = q; //r�� �������� �� ����Ʈ, r�� q, q�� p�� ���ʷ� ���󰣴�.
		q = p;
		p = p->link;
		q->link = r; //q�� ��ũ ������ �ٲ۴�.
	}
	return q; //q�� �������� �� ����Ʈ�� ��� ������
}


