#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree *new;
	BinTreeNode *new_node;

	new = malloc(sizeof(BinTree));
	if (!new)
		return (0);
	new_node = malloc(sizeof(BinTreeNode));
	if (!new_node)
		return (0);
	*new_node = rootNode;
	new->pRootNode = new_node;
	return (new);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return (0);
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new_node;

	if (!pParentNode)
		return (0);
	new_node = malloc(sizeof(BinTreeNode));
	if (!new_node)
		return (0);
	*new_node = element;
	pParentNode->pLeftChild = new_node;
	return (pParentNode->pLeftChild);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new_node;

	if (!pParentNode)
		return (0);
	new_node = malloc(sizeof(BinTreeNode));
	if (!new_node)
		return (0);
	*new_node = element;
	pParentNode->pRightChild = new_node;
	return (pParentNode->pRightChild);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (0);
	return (pNode->pLeftChild);
}
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return (0);
	return (pNode->pRightChild);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return ;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
}


void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return ;
	deleteBinTreeNode(pBinTree->pRootNode);
	free(pBinTree);
}

void display_bintree(BinTreeNode *root, BinTreeNode *parent, int level)
{
	BinTreeNode *node;

	node = root;
	printf("node : %d, parent node : %d ==== level %d\n", node->data, parent->data, level);
	if (node->pLeftChild)
		display_bintree(node->pLeftChild, node, level + 1);
	if (node->pRightChild)
		display_bintree(node->pRightChild, node, level + 1);
}
