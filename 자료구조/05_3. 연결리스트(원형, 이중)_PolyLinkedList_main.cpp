#include <stdio.h>
#include <stdlib.h>
#include "05_3. ���Ḯ��Ʈ(����, ����)_PolyLinkedList.h"

void main() {
	ListHeader list1, list2, list3;

	init(&list1);
	init(&list2);
	init(&list3);

	//���׽� 1�� ����
	insert_node_last(&list1, 3, 12);
	insert_node_last(&list1, 2, 8);
	insert_node_last(&list1, 1, 0);

	//���׽� 2�� ����
	insert_node_last(&list2, 8, 12);
	insert_node_last(&list2, -3, 10);
	insert_node_last(&list2, 10, 6);

	//���׽� 3 = ���׽� 1 + ���׽� 2
	poly_add(&list1, &list2, &list3);
	poly_print(&list3);
}