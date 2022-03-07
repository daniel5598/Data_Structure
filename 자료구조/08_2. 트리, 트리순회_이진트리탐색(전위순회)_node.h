#pragma once

#ifndef TREENode
#define TREENode

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
	int Data;
	struct TreeNode* Left, * Right;
}TreeNode;

//TreeNode* HeadNode, * EndNode;

void InitStack(void);
void Push(TreeNode*);
TreeNode* Pop(void);
int IsStackEmpty(void);

#endif