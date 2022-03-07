#include <stdio.h>
#include <stdlib.h>
#include "04_2. 리스트(연결리스트기반)_Point.h"
#include "04_2. 리스트(연결리스트기반)_Point_LinkedList.h"

void main() {
	ListNode* list1 = NULL, * list2 = NULL;
	ListNode* p;

	Point data;
	int cho;

	while (1) {
		printf("1.입력  2.출력  3.종료");
		scanf("%d", &cho);
		switch (cho) {
		case 1: { //입력
			printf("번호 이름 점수: ");
			scanf("%d %s %lf", &data.no, data.name, &data.score);
			insert_node(&list1, create_node(data, NULL));
			break;
		}
		case 2: { //출력
			display(list1);
			break;
		}
		}
		//종료
		if (cho == 3)
			break;	
	}
}