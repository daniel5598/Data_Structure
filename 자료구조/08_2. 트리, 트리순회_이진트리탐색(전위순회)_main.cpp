#include "08_2. Ʈ��, Ʈ����ȸ_����Ʈ��Ž��(������ȸ)_node.h"

//���� �Լ� ����
void InitialTree(void);
void MakeTree(void);
void Traverse(TreeNode*);
void Visit(TreeNode*);

//���� ���� ����
TreeNode* Parent, * LeftChild, * RightChild;
TreeNode* HeadNode, * EndNode;

//Ʈ�� �ʱ�ȭ
void InitializeTree(void)
{
	HeadNode = (TreeNode*)malloc(sizeof(TreeNode));
	EndNode = (TreeNode*)malloc(sizeof(TreeNode));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}

//Ʈ���� �ʱ� ����
void MakeTree() {
	Parent = (TreeNode*)malloc(sizeof(TreeNode));
	Parent->Data = 'A';

	LeftChild = (TreeNode*)malloc(sizeof(TreeNode));
	LeftChild->Data = 'B';

	RightChild = (TreeNode*)malloc(sizeof(TreeNode));
	RightChild->Data = 'C';

	Parent->Left = LeftChild;
	Parent->Right = RightChild;

	HeadNode->Left = Parent;
	HeadNode->Right = Parent;

	Parent = Parent->Left;

	LeftChild = (TreeNode*)malloc(sizeof(TreeNode));
	LeftChild->Data = 'D';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (TreeNode*)malloc(sizeof(TreeNode));
	RightChild->Data = 'E';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
	Parent = HeadNode->Right->Right;

	LeftChild = (TreeNode*)malloc(sizeof(TreeNode));
	LeftChild->Data = 'F';
	LeftChild->Left = EndNode;
	LeftChild->Right = EndNode;

	RightChild = (TreeNode*)malloc(sizeof(TreeNode));
	RightChild->Data = 'G';
	RightChild->Left = EndNode;
	RightChild->Right = EndNode;

	Parent->Left = LeftChild;
	Parent->Right = RightChild;
}

void Traverse(TreeNode* ptrNode) {
	Push(ptrNode);

	while (!IsStackEmpty()) {
		ptrNode = Pop();
		Visit(ptrNode);

		if (ptrNode->Right != EndNode)
			Push(ptrNode->Right);

		if (ptrNode->Left != EndNode)
			Push(ptrNode->Left);
	}
}

void Visit(TreeNode* ptrNode) {
	printf("%2c -> ", ptrNode->Data);
}

void main() {
	InitStack(); //������ �ʱ�ȭ
	InitializeTree(); //Ʈ���� �ʱ�ȭ
	MakeTree(); //Ʈ���� ����
	Traverse(HeadNode->Left); //Ʈ���� ��ȯ	
}