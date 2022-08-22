#include "bintree.h"
#include <stdlib.h>
#include <stdio.h>

BinTreeNode *BinSearch(BinTreeNode *root, int key)
{
	BinTreeNode *node;
	if (!root)
		return (0);
	node = root;
	
	while (node)
	{
		if (node->data == key)
			break;
		else if(node->data > key)
			node = node->pLeftChild;
		else if(node->data < key)
			node = node->pRightChild;
	}
	//printf("testestsets : %d\n", node->data);
	return (node);
}

int insert_bst(BinTreeNode *root, int key)
{
	BinTreeNode *temp;
	BinTreeNode *new_node;

	new_node = malloc(sizeof(BinTreeNode));
	if (!new_node)
		return (0);
	new_node->data = key;
	new_node->pLeftChild = 0;
	new_node->pRightChild = 0;
	temp = root;
	while (temp)
	{
		if (root->data == key)
			return (0);
		else if (temp->data > key)
		{
			if (!temp->pLeftChild)
			{
				temp->pLeftChild = new_node;
				return (1);
			}
			temp = temp->pLeftChild;
		}
		else if (temp->data < key)
		{
			if (!temp->pRightChild)
			{
				temp->pRightChild = new_node;
				return (1);
			}
			temp = temp->pRightChild;
		}
		// if (!temp)
		// {
		// 	// printf("test here\n");
		// 	// printf("new node : %d\n",new_node->data);
		// 	temp = new_node;
		// 	display_bintree(root, 0);
		// 	return (1);
		// }
	}
	return (0);
}
