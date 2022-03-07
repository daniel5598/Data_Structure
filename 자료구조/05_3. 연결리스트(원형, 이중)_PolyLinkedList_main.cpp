#include <stdio.h>
#include <stdlib.h>
#include "05_3. 연결리스트(원형, 이중)_PolyLinkedList.h"

void main() {
	ListHeader list1, list2, list3;

	init(&list1);
	init(&list2);
	init(&list3);

	//다항식 1을 생성
	insert_node_last(&list1, 3, 12);
	insert_node_last(&list1, 2, 8);
	insert_node_last(&list1, 1, 0);

	//다항식 2를 생성
	insert_node_last(&list2, 8, 12);
	insert_node_last(&list2, -3, 10);
	insert_node_last(&list2, 10, 6);

	//다항식 3 = 다항식 1 + 다항식 2
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);
}