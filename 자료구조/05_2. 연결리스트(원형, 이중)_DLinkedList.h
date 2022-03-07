#pragma once
#ifndef DLinked_List_H
#define DLinked_List_H

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct DlistNode {
	element data;
	struct DlistNode* llink;
	struct DlistNode* rlink;
}DlistNode;

void init(DlistNode* phead);
void display(DlistNode* phead);
void dinsert_node(DlistNode* before, DlistNode* new_node);
void dremove_node(DlistNode* phead_node, DlistNode* removed);

#endif