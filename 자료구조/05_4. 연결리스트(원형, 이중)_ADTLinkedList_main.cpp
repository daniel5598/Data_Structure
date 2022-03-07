#include <stdio.h>
#include <stdlib.h>
#include "05_4. 연결리스트(원형, 이중)_ADTLinkedList.h"

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

	printf("%s\n", is_in_list(&list1, 20) == TRUE ? "성공" : "실패");
	printf("%d\n", get_entry(&list1, 0));

}