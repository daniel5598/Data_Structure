#include <stdio.h>
#include <stdlib.h>
#include "04_2. ����Ʈ(���Ḯ��Ʈ���)_Point.h"
#include "04_2. ����Ʈ(���Ḯ��Ʈ���)_Point_LinkedList.h"

void main() {
	ListNode* list1 = NULL, * list2 = NULL;
	ListNode* p;

	Point data;
	int cho;

	while (1) {
		printf("1.�Է�  2.���  3.����");
		scanf("%d", &cho);
		switch (cho) {
		case 1: { //�Է�
			printf("��ȣ �̸� ����: ");
			scanf("%d %s %lf", &data.no, data.name, &data.score);
			insert_node(&list1, create_node(data, NULL));
			break;
		}
		case 2: { //���
			display(list1);
			break;
		}
		}
		//����
		if (cho == 3)
			break;	
	}
}