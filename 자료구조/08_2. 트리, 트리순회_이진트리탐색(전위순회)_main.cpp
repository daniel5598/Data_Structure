#include "08_2. 트리, 트리순회_이진트리탐색(전위순회)_node.h"

//내부 함수 정의
void InitialTree(void);
void MakeTree(void);
void Traverse(TreeNode*);
void Visit(TreeNode*);

//전역 변수 정의
TreeNode* Parent, * LeftChild, * RightChild;
TreeNode* HeadNode, * EndNode;

//트리 초기화
void InitializeTree(void)
{
	HeadNode = (TreeNode*)malloc(sizeof(TreeNode));
	EndNode = (TreeNode*)malloc(sizeof(TreeNode));

	HeadNode->Left = EndNode;
	HeadNode->Right = EndNode;

	EndNode->Left = EndNode;
	EndNode->Right = EndNode;
}

//트리의 초기 구성
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
	InitStack(); //스택의 초기화
	InitializeTree(); //트리의 초기화
	MakeTree(); //트리의 구성
	Traverse(HeadNode->Left); //트리의 순환	
}