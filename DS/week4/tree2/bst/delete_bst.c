#include "bintree.h"
#include "bst.h"

BinTreeNode *find_delete_node(BinTreeNode *root, BinTreeNode *p_del, int key, int *direction)
{
    BinTreeNode *del;

	del = root;
    while (del)
	{
		if (del->data == key)
			break;
		p_del = del;
		if (del->data > key)
		{
			del = del->pLeftChild;
			*direction = 1;
		}
		else
		{	
			del = del->pRightChild;
			*direction = 2;
		}
	}
	return (del);
}

int delete_bst(BinTreeNode *root, int key)
{
	BinTreeNode *del;
	BinTreeNode *p_del;
	BinTreeNode *c_del;
	BinTreeNode *temp;
	int 		direction; //1 left, 2 right

	del = root;
	p_del = root;
	direction = 0;
	del = find_delete_node(root, p_del, key, &direction);
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
		// 삭제할 노드의 자식노드가 2개 있는 경우
		// 삭제하고도 정렬이 되어야 하므로 왼쪽노드에서 가장 큰 수를 찾는다
		// 이유는 왼쪽노드의 가장 큰수라고 할지라도 오른쪽 대상보다는 작게 된다.
		// 그렇게 하면 오른쪽 노드는 아예 안건드려도 된다.
		// 왼쪽노드의 가장 큰수는 트리에서 계속 오른쪽으로 가서(오른쪽이 큰 수이므로)
		// 마지막이 되므로 오른쪽 노드는 없다.
		// 그래서 이 큰 수를 위로 올리면 왼쪽 노드에 대해서만 고민을 해주면 되는데
		// 그 왼쪽 노드는 원래 이 큰 수가 있던 곳에 집어 넣어주면 된다.
		temp = del->pLeftChild;
		if (!temp->pRightChild)
		{
			del->data = temp->data;
			del->pLeftChild = temp->pLeftChild;
			return (1);
		}

		while (1)
		{
			if (!temp->pRightChild)
			{
				del->data = temp->data;
				p_del->pRightChild = temp->pLeftChild;
				return (1);
			}
			else
			{
				p_del = temp;
				temp = temp->pRightChild;
			}
		}
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