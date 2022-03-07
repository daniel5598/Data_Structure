#pragma once
#ifndef ADTLinked_LIST_H
#define ADTLinked_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;
typedef struct {
	ListNode* head; //헤드 포인터
	int length; //노드의 개수
}ListType;

void insert_node(ListNode** phead, ListNode* p, ListNode* new_node);
void remove_node(ListNode** phead, ListNode* p, ListNode* removed);
void init(ListType* list);

ListNode* get_node_at(ListType* list, int pos);

int get_length(ListType* list);

void error(char* message);
void add(ListType* list, int position, element data);
void add_last(ListType* list, element data);
void add_first(ListType* list, element data);

int is_empty(ListType* list);

void delete_entry(ListType* list, int pos);
element get_entry(ListType* list, int pos);

void clear(ListType* list);
void display(ListType* list);

int is_in_list(ListType* list, element item);

#endif
