#pragma once
#ifndef Linked_LIST_H
#define Linked_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* create_node(element data, ListNode* link);
void insert_first(ListNode** phead, ListNode* node);
void insert_last(ListNode** phead, ListNode* node);
void display(ListNode* head);

#endif