#include <stdio.h>
#include <stdlib.h>
#include "05_1. 연결리스트(원형, 이중)_LinkedList.h"

void main() {
	ListNode* list1 = NULL;

	//list1 = 20->10->30
	insert_first(&list1, create_node(10, NULL));
	insert_first(&list1, create_node(20, NULL));
	insert_last(&list1, create_node(30, NULL));
	display(list1);
}