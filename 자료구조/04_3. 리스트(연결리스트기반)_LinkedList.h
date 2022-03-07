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

//�Է�
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node); 
//����
ListNode* create_node(int data, ListNode* link);
//���
void display(ListNode* head);
void display_recur(ListNode* head);
//����
void remove_node(ListNode** phead, ListNode* p, ListNode* removed);
//�˻�
ListNode* search(ListNode* head, int x);
//����
ListNode* concat(ListNode* head1, ListNode* head2);
//����
ListNode* reverse(ListNode* head);

#endif