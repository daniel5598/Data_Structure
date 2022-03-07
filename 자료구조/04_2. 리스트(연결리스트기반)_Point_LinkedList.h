#pragma once

#ifndef Point_Linked_List_H
#define Point_Linked_List_H

#include "04_2. ����Ʈ(���Ḯ��Ʈ���)_Point.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	Point data;
	struct ListNode* link;
}ListNode;

void insert_node(ListNode** phead, ListNode* new_node); //�Է�
void display(ListNode* head); //���
ListNode* create_node(Point data, ListNode* link); //����

#endif