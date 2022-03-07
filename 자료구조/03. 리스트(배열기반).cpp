#include<stdio.h>
#include<string.h>
#define MAX_SIZE 50
typedef struct{
	char name[MAX_SIZE];
	int num;
	int price;
	char sort[MAX_SIZE];
}item;
void enter(item* far,int i) // *==[]
{
	printf("품명을 입력하시오:");
	scanf("%s",&far[i].name);
	printf("수량을 입력하시오:");
	scanf("%d",&far[i].num);
	printf("단가를 입력하시오:");
	scanf("%d",&far[i].price);
	printf("구분을 하시오(식품, 문구, 의류):");
	scanf("%s",&far[i].sort);
}
void disp(item* far, int i)
{
	printf("\n%10s%10s%10s%10s\n", "품명", "수량", "단가", "구분");
	for (int m = 0; m < i; m++)
	{
		printf("%10s%10d%10d%10s", far[m].name, far[m].num, far[m].price, far[m].sort);
		putchar('\n');
	}
}
void del(item* far, int i)
{
	char tmpname[MAX_SIZE];
	int m;
	printf("품명을 입력하시오:");
	scanf("%s",&tmpname);
	for (m = 0; m < i; m++)
	{
		if (strcmp(tmpname ,far[m].name)==0)break;
	}
	for (int n = m; n < i; n++)
	{
		far[n] = far[n+1];
	}
}
void add(item* far, int i)
{
	char tmpname[MAX_SIZE];
	int m,n;
	printf("삽입할 품명을 입력하시오:");
	scanf("%s",&tmpname);
	for (m = 0; m < i; m++)
	{
		if (strcmp(tmpname, far[m].name) == 0)break;
	}
	for (n = i; n> m; n--)
	{
		far[n] = far[n - 1];
	}
	printf("품명을 입력하시오:");
	scanf("%s", &far[m].name);
	printf("수량을 입력하시오:");
	scanf("%d", &far[m].num);
	printf("단가를 입력하시오:");
	scanf("%d", &far[m].price);
	printf("구분을 하시오(식품, 문구, 의류):");
	scanf("%s", &far[m].sort);
}
void main()
{
	item arr[10];
	int num,i=0;
	
	for (;;) {
		printf("1.추가\n2.출력\n3.삭제\n4.삽입\n5.종료\n->");
		scanf("%d",&num);
		if (num == 1) 
		{
			enter(arr,i++);
		}
		else if (num == 2)
		{
			disp(arr, i);
		}
		else if (num == 3)
		{
			del(arr, i);
			i--;
		}
		else if (num == 4)
		{
			i++;
			add(arr, i);
		}
		else if (num == 5)break;
		else
		{
			printf("다시 입력해주세요.");
		}
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 50
typedef struct itemInfo
{
	char name[MAX_SIZE];
	int num;
	int price;
	char sort[MAX_SIZE];
	struct itemInfo* next;
};
itemInfo* enter(itemInfo* sp)
{
	itemInfo* ep;
	if (sp == NULL)
	{
		sp = (itemInfo*)malloc(sizeof(itemInfo));
		ep = sp;
	}
	else
	{
		ep = sp;
		for (;;)
		{
			if (ep->next == NULL)
			{
				break;
			}
			ep = ep->next;
		}
		ep->next = (itemInfo*)malloc(sizeof(itemInfo));
		ep = ep->next;
	}
	printf("품명을 입력하시오:");
	scanf("%s", &ep->name);
	printf("수량을 입력하시오:");
	scanf("%d", &ep->num);
	printf("단가를 입력하시오:");
	scanf("%d", &ep->price);
	printf("구분을 하시오(식품, 문구, 의류):");
	scanf("%s", &ep->sort);
	ep->next = NULL;
	return sp;
}
void disp(itemInfo* sp)
{
	while (1)
	{
		if (sp == NULL)break;
		printf("품명:%3s ", sp->name);
		printf("수량:%3d ", sp->num);
		printf("단가:%3d ", sp->price);
		printf("구분:%3s ", sp->sort);
		printf("\n");
		sp = sp->next;
	}
}
itemInfo* del(itemInfo* sp)
{
	itemInfo* backcp = NULL;
	itemInfo* cp = sp;
	char tmpname[MAX_SIZE];
	printf("품명을 입력하시오:");
	scanf("%s", &tmpname);
	if (strcmp(tmpname, cp->name) == 0)
	{
		sp = cp->next;
	}
	else
	{
		while (1)
		{
			if (cp == NULL)
				break;
			if (strcmp(tmpname, cp->name) == 0)
			{
				backcp->next = cp->next;
				break;
			}
			backcp = cp;
			cp = cp->next;
		}
		if (cp == NULL)
		{
			printf("찾으신 품목이 없습니다.\n");

		}
	}
	return sp;
}
void add(itemInfo* sp)
{
	itemInfo* itemInclude;
	itemInfo* cp = sp;
	char tmpname[MAX_SIZE];
	printf("추가할 위치의 품목명을 입력하시오:");
	scanf("%s", &tmpname);
	while (1)
	{
		if (cp == NULL)
			break;
		if (strcmp(tmpname, cp->name) == 0)
		{
			itemInclude = cp->next;
			cp->next = (itemInfo*)malloc(sizeof(itemInfo));
			cp = cp->next;
			printf("품명을 입력하시오:");
			scanf("%s", &cp->name);
			printf("수량을 입력하시오:");
			scanf("%d", &cp->num);
			printf("단가를 입력하시오:");
			scanf("%d", &cp->price);
			printf("구분을 하시오(식품, 문구, 의류):");
			scanf("%s", &cp->sort);
			cp->next = itemInclude;
			break;
		}
		itemInclude = cp;
		cp = cp->next;

	}
	if (cp == NULL)
	{
		printf("찾으신 품목이 없습니다.\n");

	}
}
void main()
{
	int num1;
	itemInfo* sp;
	sp=NULL;
	while (1)
	{
		printf("1.입력 2.출력 3.삭제 4.삽입 5.종료\n->");
		scanf("%d", &num1);
		if (num1 == 1)
		{
			sp=enter(sp);
		}
		else if (num1 == 2)
		{
			disp(sp);
		}
		else if (num1 == 3)
		{
			sp=del(sp);
		}
		else if (num1 == 4)
		{
			add(sp);
		}
		else
			break;
	}
}

