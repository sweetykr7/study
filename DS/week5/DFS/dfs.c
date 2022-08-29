#include "linkedstack.h"
#include "linkedlist.h"
#include "linkedgraph.h"
#include <stdio.h>
#include <stdlib.h>

int pushStack_forDFS(LinkedStack *stk, int pushID)
{
	StackNode node;

	node.data = pushID;
	node.pLink = 0;
	return (pushLS(stk, node));
}

void dfs_graph(LinkedGraph *pGraph, int startID)
{
	LinkedStack *stk;
	ListNode	*temp;
	StackNode	*stk_node;
	int			*visited;
	int			vertax_id;

	if (!pGraph)
		return ;
	stk = createLinkedStack();
	if (!stk)
		return ;
	visited = malloc(sizeof(int) * pGraph->maxVertexCount);
	if (!visited)
		return ;
	//memset(visited, 0, sizeof(int) * pGraph->maxVertexCount);
	visited[startID] = 1;
	pushStack_forDFS(stk, startID);
	while (!isLinkedStackEmpty(stk))
	{
		stk_node = popLS(stk);
		if (!stk_node)
			break ;
		vertax_id = stk_node->data;
		printf("[%d]\n", vertax_id);
		temp = pGraph->ppAdjEdge[vertax_id]->headerNode.pLink;
		while (temp)
		{
			vertax_id = temp->data;
			if (!visited[vertax_id])
			{
				visited[vertax_id] = 1;
				pushStack_forDFS(stk, vertax_id);
			}
			temp = temp->pLink;
		}
	}
	printf("\n");
}
