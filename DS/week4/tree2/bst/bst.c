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

int delete_bst(BinTreeNode *root, int key)
{
	BinTreeNode *del;
	BinTreeNode *p_del;
	BinTreeNode *c_del;
	BinTreeNode *large_node_under_del;
	BinTreeNode *p_large_node_under_del;
	int 		direction; //1 left, 2 right

	del = root;
	p_del = root;
	direction = 0;
	while (del)
	{
		if (del->data == key)
			break;
		p_del = del;
		if (del->data > key)
		{
			del = del->pLeftChild;
			direction = 1;
		}
		else
		{	
			del = del->pRightChild;
			direction = 2;
		}
	}
	if (!del)
	{
		printf("%d is not here\n", key);
		return (0); // none key;
	}
	if (!del->pLeftChild && !del->pRightChild)
	{
		if (p_del)
		{
			if (direction == 1)
				p_del->pLeftChild = 0;
			else if (direction == 2)
				p_del->pRightChild = 0;
		}
		else
			root = 0;
	}
	else if (del->pLeftChild && del->pRightChild)
	{
		// printf("check here=====\n");
		// exit(0);
		p_large_node_under_del = del;
		large_node_under_del = del->pLeftChild;
		while (large_node_under_del->pRightChild)
		{
			p_large_node_under_del = large_node_under_del;
			large_node_under_del = large_node_under_del->pRightChild;
		}

		p_large_node_under_del->pRightChild = large_node_under_del->pLeftChild;
		large_node_under_del->pLeftChild = del->pLeftChild;
		large_node_under_del->pRightChild = del->pRightChild;
		if (p_del)
		{
			if (direction == 1)
			{
				p_del->pLeftChild = large_node_under_del;
				// printf("test here\n");
				// exit(0)
			}
			else if (direction == 2)
				p_del->pRightChild = large_node_under_del;
			;
		}
		else
			root = large_node_under_del;

	}
	else // 1 child node of del
	{
		if (del->pLeftChild)
			c_del = del->pLeftChild;
		else
			c_del = del->pRightChild;
		
		if (p_del)
		{
			if (direction == 1)
				p_del->pLeftChild = c_del;
			else if (direction == 2)
				p_del->pRightChild = c_del;
		}
		else
			root = c_del;
	}

	free(del);
	return (1);
}