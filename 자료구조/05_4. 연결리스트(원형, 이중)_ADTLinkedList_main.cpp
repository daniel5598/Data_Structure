#include <stdio.h>
#include <stdlib.h>
#include "05_4. ���Ḯ��Ʈ(����, ����)_ADTLinkedList.h"

void main() {
	ListType list1;

	init(&list1);
	add(&list1, 0, 20);
	add_last(&list1, 30);
	add_first(&list1, 10);
	add_last(&list1, 40);

	//list1 = (10, 20, 30, 40)
	display(&list1);

	//list1 = (10, 20, 30)
	delete_entry(&list1, 3);
	display(&list1);

	//list1 = (20, 30)
	delete_entry(&list1, 0);
	display(&list1);

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "����" : "����");
	printf("%d\n", get_entry(&list1, 0));

}