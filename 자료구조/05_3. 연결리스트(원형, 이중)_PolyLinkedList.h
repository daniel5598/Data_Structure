#pragma once
#ifndef PLinked_LIST_H
#define PLinked_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode {
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListHeader {
	int length;
	ListNode* head;
	ListNode* tail;
};

void init(ListHeader* plist);
void insert_node_last(ListHeader* plist, int coef, int expon);
void poly_add(ListHeader* plist1, ListHeader* plist2, ListHeader* plist3);
void poly_print(ListHeader* plist);

#endif