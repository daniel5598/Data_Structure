#include<stdio.h>
#include<stdlib.h>
typedef struct struct_node {
	int data;
	struct_node* next;
}Node;

int main(void) {
	Node* head = NULL; //NULL 포인터 초기화
	Node* tail = NULL;
	Node* cur = NULL;
	Node* newNode = NULL;
	int readData;

	/****데이터를 입력받는 과정****/
	while(1) {
		printf("자연수 입력 (1보다 작으면 종료): ");
		scanf("%d", &readData);
		if (readData < 1)
			break;
		/***노드의 추가과정***/
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;
		tail = newNode;
	}
	printf("\n");

	/****입력 받은 데이터의 출력과정****/
	printf("입력 받은 데이터의 전체출력!\n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다.\n");
	}
	else {
		cur = head;
		printf("%d ", cur->data); //첫 번째 데이터 출력

		while (cur->next != NULL) //두 번째 이후의 데이터 출력
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n\n");
	return 0;
}

