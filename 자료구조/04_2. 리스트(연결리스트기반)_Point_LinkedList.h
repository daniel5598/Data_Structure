#pragma once

#ifndef Point_Linked_List_H
#define Point_Linked_List_H

#include "04_2. 리스트(연결리스트기반)_Point.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	Point data;
	struct ListNode* link;
}ListNode;

void insert_node(ListNode** phead, ListNode* new_node); //입력
void display(ListNode* head); //출력
ListNode* create_node(Point data, ListNode* link); //생성

#endif