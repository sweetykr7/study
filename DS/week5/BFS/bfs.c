#include "arrayqueue.h"
#include "linkedlist.h"
#include "linkedgraph.h"
#include <stdio.h>
#include <stdlib.h>

int endeque_forBFS(ArrayQueue *queue, int pushID)
{
	ArrayQueueNode node;

	node.data = pushID;
	return (enqueueAQ(queue, node));
}

void bfs_graph(LinkedGraph *pGraph, int startID)
{
	ArrayQueue		*queue;
	ArrayQueueNode	*node;
	ListNode		*temp;
	int				*visited;
	int				vertax_id;

	if (!pGraph)
		return ;
	queue = createArrayQueue(pGraph->maxVertexCount);
	if (!queue)
		return ;
	visited = malloc(sizeof(int) * pGraph->maxVertexCount);
	if (!visited)
		return ;
	visited[startID] = 1;
	endeque_forBFS(queue, startID);
	while (queue->currentElementCount > 0)
	{
		node = dequeueAQ(queue);
		vertax_id = node->data;	
		printf("[%d]\n", node->data);
		temp = pGraph->ppAdjEdge[vertax_id]->headerNode.pLink;
		while (temp)
		{
			vertax_id = temp->data;
			if (!visited[vertax_id])
			{
				visited[vertax_id] = 1;
				endeque_forBFS(queue, vertax_id);
			}
			temp = temp->pLink;
		}
	}
	printf("\n");
}
