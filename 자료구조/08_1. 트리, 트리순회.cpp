//���� Ʈ���� ��ũ�� ǥ��
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

	n1->data = 10; //ù��° ��带 �����Ѵ�.
	n1->left = n2;
	n1->right = n3;

	n2->data = 20; //�ι�° ��带 �����Ѵ�.
	n2->right = NULL;
	n2->left = NULL;

	n3->data = 30; //����° ��带 �����Ѵ�.
	n3->left = NULL;
	n3->right = NULL;
}