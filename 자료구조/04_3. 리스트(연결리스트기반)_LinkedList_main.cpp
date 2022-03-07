#include <stdio.h>
#include <stdlib.h>
#include "04_3. 리스트(연결리스트기반)_LinkedList.h"
#include "04_3. 리스트(연결리스트기반)_LinkedList.cpp"

void main(void) {
	ListNode* list1 = NULL, * list2 = NULL;
	ListNode* p;
	int cho, num;

	while (1) {
		printf("1.입력  2.출력  3.삭제  4.검색  5.연결  6.역순  7.종료: ");
		scanf("%d", &cho);

		switch (cho)
		{
		case 1: { //입력
			printf("정수 입력: ");
			scanf("%d", &num);
			insert_node(&list1, NULL, create_node(num, NULL));
			break;
		}
		case 2: { //출력
			display(list1);
			display_recur(list1);
			printf("\n\n");
			break;
		}
		case 3: { //삭제
			remove_node(&list1, NULL, list1);
			break;
		}
		case 4: { //검색
			printf("정수 입력:");
			scanf("%d", &num);
			list2 = search(list1, num);
			if (list2 == NULL)
				printf("저장된 값이 없습니다");
			else
				printf("=> %d", "list2->data");
			break;
		}
		case 5: { //연결
			insert_node(&list2, NULL, create_node(100, NULL));
			insert_node(&list2, NULL, create_node(110, NULL));
			insert_node(&list2, NULL, create_node(120, NULL));
			insert_node(&list2, NULL, create_node(130, NULL));
			insert_node(&list2, NULL, create_node(140, NULL));
			display(list2);
			list1 = concat(list1, list2);
		}
		case 6: {//역순
			list1 = reverse(list1);
			break;
		}
		}
		//종료
		if (cho == 7)break;
	}
}