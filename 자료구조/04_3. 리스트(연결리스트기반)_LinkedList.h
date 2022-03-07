#pragma once
#ifndef Linked_LIST_H
#define Linked_LIST_H

#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

//입력
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node); 
//생성
ListNode* create_node(int data, ListNode* link);
//출력
void display(ListNode* head);
void display_recur(ListNode* head);
//삭제
void remove_node(ListNode** phead, ListNode* p, ListNode* removed);
//검색
ListNode* search(ListNode* head, int x);
//연결
ListNode* concat(ListNode* head1, ListNode* head2);
//역순
ListNode* reverse(ListNode* head);

#endif