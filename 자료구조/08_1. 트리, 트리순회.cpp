//이진 트리를 링크로 표현
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

void main() {
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10; //첫번째 노드를 설정한다.
	n1->left = n2;
	n1->right = n3;

	n2->data = 20; //두번째 노드를 설정한다.
	n2->right = NULL;
	n2->left = NULL;

	n3->data = 30; //세번째 노드를 설정한다.
	n3->left = NULL;
	n3->right = NULL;
}