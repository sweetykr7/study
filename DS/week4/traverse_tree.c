#include "bintree.h"
#include <stdio.h>

void preorderTraverse(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	
	printf("Node data is %c\n", pNode->data);
	preorderTraverse(pNode->pLeftChild);
	preorderTraverse(pNode->pRightChild);
}

void inorderTraverse(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	
	inorderTraverse(pNode->pLeftChild);
	printf("Node data is %c\n", pNode->data);
	inorderTraverse(pNode->pRightChild);
}

void postorderTraverse(BinTreeNode *pNode)
{
	if (!pNode)
		return ;
	
	postorderTraverse(pNode->pLeftChild);
	postorderTraverse(pNode->pRightChild);
	printf("Node data is %c\n", pNode->data);
}

//test 222