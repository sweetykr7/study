#include "bintree.h"
#include <stdio.h>

// typedef struct BinTreeNodeType
// {
// 	char data;
// 	int visited;

// 	struct BinTreeNodeType* pLeftChild;
// 	struct BinTreeNodeType* pRightChild;
// } BinTreeNode;

// typedef struct BinTreeType
// {
// 	struct BinTreeNodeType* pRootNode;
// } BinTree;

// BinTreeNode* getRootNodeBT(BinTree* pBinTree)

// BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)

// BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)

// BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)

// BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)

// void deleteBinTreeNode(BinTreeNode* pNode)

// void deleteBinTree(BinTree* pBinTree)


int main(void)
{
	BinTree *tree;
	BinTreeNode node;

	node.data = 'a';
	node.pLeftChild = 0;
	node.pRightChild = 0;
	node.visited = 0;

	tree = makeBinTree(node);

	node.data = 'b';
	node.pLeftChild = 0;
	node.pRightChild = 0;
	node.visited = 0;

	insertLeftChildNodeBT(tree->pRootNode, node);
	
	node.data = 'c';
	node.pLeftChild = 0;
	node.pRightChild = 0;
	node.visited = 0;

	insertRightChildNodeBT(tree->pRootNode, node);

	printf("root node data : %c\n", getRootNodeBT(tree)->data);
	printf("left node data : %c\n", getLeftChildNodeBT(tree->pRootNode)->data);
	printf("right node data : %c\n", getRightChildNodeBT(tree->pRootNode)->data);


	printf("traverse ===============================\n");
	printf("preorder ===============================\n");
	preorderTraverse(tree->pRootNode);
	printf("inorder ===============================\n");
	inorderTraverse(tree->pRootNode);
	printf("postorder ===============================\n");
	postorderTraverse(tree->pRootNode);
	
	// deleteBinTree(tree);
	// printf("root node data : %c\n", getRootNodeBT(tree)->data);

	

	return (0);
}