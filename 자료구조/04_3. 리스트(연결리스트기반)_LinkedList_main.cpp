#include <stdio.h>
#include <stdlib.h>
#include "04_3. ����Ʈ(���Ḯ��Ʈ���)_LinkedList.h"
#include "04_3. ����Ʈ(���Ḯ��Ʈ���)_LinkedList.cpp"

void main(void) {
	ListNode* list1 = NULL, * list2 = NULL;
	ListNode* p;
	int cho, num;

	while (1) {
		printf("1.�Է�  2.���  3.����  4.�˻�  5.����  6.����  7.����: ");
		scanf("%d", &cho);

		switch (cho)
		{
		case 1: { //�Է�
			printf("���� �Է�: ");
			scanf("%d", &num);
			insert_node(&list1, NULL, create_node(num, NULL));
			break;
		}
		case 2: { //���
			display(list1);
			display_recur(list1);
			printf("\n\n");
			break;
		}
		case 3: { //����
			remove_node(&list1, NULL, list1);
			break;
		}
		case 4: { //�˻�
			printf("���� �Է�:");
			scanf("%d", &num);
			list2 = search(list1, num);
			if (list2 == NULL)
				printf("����� ���� �����ϴ�");
			else
				printf("=> %d", "list2->data");
			break;
		}
		case 5: { //����
			insert_node(&list2, NULL, create_node(100, NULL));
			insert_node(&list2, NULL, create_node(110, NULL));
			insert_node(&list2, NULL, create_node(120, NULL));
			insert_node(&list2, NULL, create_node(130, NULL));
			insert_node(&list2, NULL, create_node(140, NULL));
			display(list2);
			list1 = concat(list1, list2);
		}
		case 6: {//����
			list1 = reverse(list1);
			break;
		}
		}
		//����
		if (cho == 7)break;
	}
}