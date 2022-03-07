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
	printf("ǰ���� �Է��Ͻÿ�:");
	scanf("%s",&far[i].name);
	printf("������ �Է��Ͻÿ�:");
	scanf("%d",&far[i].num);
	printf("�ܰ��� �Է��Ͻÿ�:");
	scanf("%d",&far[i].price);
	printf("������ �Ͻÿ�(��ǰ, ����, �Ƿ�):");
	scanf("%s",&far[i].sort);
}
void disp(item* far, int i)
{
	printf("\n%10s%10s%10s%10s\n", "ǰ��", "����", "�ܰ�", "����");
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
	printf("ǰ���� �Է��Ͻÿ�:");
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
	printf("������ ǰ���� �Է��Ͻÿ�:");
	scanf("%s",&tmpname);
	for (m = 0; m < i; m++)
	{
		if (strcmp(tmpname, far[m].name) == 0)break;
	}
	for (n = i; n> m; n--)
	{
		far[n] = far[n - 1];
	}
	printf("ǰ���� �Է��Ͻÿ�:");
	scanf("%s", &far[m].name);
	printf("������ �Է��Ͻÿ�:");
	scanf("%d", &far[m].num);
	printf("�ܰ��� �Է��Ͻÿ�:");
	scanf("%d", &far[m].price);
	printf("������ �Ͻÿ�(��ǰ, ����, �Ƿ�):");
	scanf("%s", &far[m].sort);
}
void main()
{
	item arr[10];
	int num,i=0;
	
	for (;;) {
		printf("1.�߰�\n2.���\n3.����\n4.����\n5.����\n->");
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
			printf("�ٽ� �Է����ּ���.");
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
	printf("ǰ���� �Է��Ͻÿ�:");
	scanf("%s", &ep->name);
	printf("������ �Է��Ͻÿ�:");
	scanf("%d", &ep->num);
	printf("�ܰ��� �Է��Ͻÿ�:");
	scanf("%d", &ep->price);
	printf("������ �Ͻÿ�(��ǰ, ����, �Ƿ�):");
	scanf("%s", &ep->sort);
	ep->next = NULL;
	return sp;
}
void disp(itemInfo* sp)
{
	while (1)
	{
		if (sp == NULL)break;
		printf("ǰ��:%3s ", sp->name);
		printf("����:%3d ", sp->num);
		printf("�ܰ�:%3d ", sp->price);
		printf("����:%3s ", sp->sort);
		printf("\n");
		sp = sp->next;
	}
}
itemInfo* del(itemInfo* sp)
{
	itemInfo* backcp = NULL;
	itemInfo* cp = sp;
	char tmpname[MAX_SIZE];
	printf("ǰ���� �Է��Ͻÿ�:");
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
			printf("ã���� ǰ���� �����ϴ�.\n");

		}
	}
	return sp;
}
void add(itemInfo* sp)
{
	itemInfo* itemInclude;
	itemInfo* cp = sp;
	char tmpname[MAX_SIZE];
	printf("�߰��� ��ġ�� ǰ����� �Է��Ͻÿ�:");
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
			printf("ǰ���� �Է��Ͻÿ�:");
			scanf("%s", &cp->name);
			printf("������ �Է��Ͻÿ�:");
			scanf("%d", &cp->num);
			printf("�ܰ��� �Է��Ͻÿ�:");
			scanf("%d", &cp->price);
			printf("������ �Ͻÿ�(��ǰ, ����, �Ƿ�):");
			scanf("%s", &cp->sort);
			cp->next = itemInclude;
			break;
		}
		itemInclude = cp;
		cp = cp->next;

	}
	if (cp == NULL)
	{
		printf("ã���� ǰ���� �����ϴ�.\n");

	}
}
void main()
{
	int num1;
	itemInfo* sp;
	sp=NULL;
	while (1)
	{
		printf("1.�Է� 2.��� 3.���� 4.���� 5.����\n->");
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

