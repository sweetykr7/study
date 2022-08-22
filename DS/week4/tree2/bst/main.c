#include "bintree.h"
#include "bst.h"
#include <stdlib.h>
#include <stdio.h>
//#include "bintree.c"
//#include "bst.c"
//#include "delete_bst.c" 

int main(void)
{
	BinTree *tree;
	BinTreeNode *node;
	BinTreeNode	*left_node;
	BinTreeNode *right_node;
	BinTreeNode *temp_node;

	node = calloc(1, sizeof(BinTreeNode));
	left_node = calloc(1, sizeof(BinTreeNode));
	right_node = calloc(1, sizeof(BinTreeNode));
	node->data = 10;
	node->pLeftChild = 0;
	node->pRightChild = 0;
	left_node->pLeftChild = 0;
	left_node->pRightChild = 0;
	right_node->pLeftChild = 0;
	right_node->pRightChild = 0;
	tree = makeBinTree(*node);
	node = tree->pRootNode;
	left_node->data = 3;
	insertLeftChildNodeBT(node, *left_node);
	left_node->data = -1;
	insertLeftChildNodeBT(node->pLeftChild, *left_node);
	left_node->data = 5;
	insertRightChildNodeBT(node->pLeftChild, *left_node);

	right_node->data = 15;
	insertRightChildNodeBT(node, *right_node);
	right_node->data = 12;
	insertLeftChildNodeBT(node->pRightChild, *right_node);
	right_node->data = 27;
	insertRightChildNodeBT(node->pRightChild, *right_node);
	display_bintree(tree->pRootNode, tree->pRootNode, 0);
	printf("====================================\n");
	temp_node = BinSearch(node, 10);
	printf("search test : %d\n", temp_node->data);
	printf("====================================\n");
	printf("====================================\n");
	printf("insert_test : 11\n");
	insert_bst(node, 11);
	display_bintree(tree->pRootNode, tree->pRootNode, 0);
	printf("====================================\n");
	printf("delete_test : 3\n");
	//delete_bst(node, 3);
	delete_bst(node, 15);
	display_bintree(tree->pRootNode, tree->pRootNode, 0);
	// printf("test node : %d\n", node->pRightChild->data);
	// printf("test node : %d\n", node->pRightChild->pLeftChild->data);
	// printf("test node : %d\n", node->pRightChild->pLeftChild->pLeftChild->data);
	// printf("test node : %d\n", node->pRightChild->pLeftChild->pLeftChild->pRightChild->data);
	printf("====================================\n");
	return (0);
}