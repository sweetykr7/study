#include "linkedgraph.h"

// typedef struct LinkedGraphType
// {
// 	int maxVertexCount;		
// 	int currentVertexCount;	
// 	int currentEdgeCount;	 // ? ?????
// 	int graphType;			// 1-Undirected, 2-Directed
// 	LinkedList** ppAdjEdge;	
// 	int *pVertex;			
// } LinkedGraph;

LinkedGraph* createLinkedGraph(int maxVertexCount)
{
	LinkedGraph *new;
	LinkedList	**ppAdjEdge;		
	int			*pVertex;			

	pVertex = malloc(sizeof(int) * maxVertexCount);
	if (!pVertex)
		return (0);
	new = malloc(sizeof(LinkedGraph));
	if (!new)
		return (0);
	ppAdjEdge = malloc(sizeof(LinkedList *) * maxVertexCount);
	if (!ppAdjEdge)
		return (0);
	for (int i = 0; i < maxVertexCount; i++)
	{
		ppAdjEdge[i] = createLinkedList();
	}
	//printf("check================\n");
	new->pVertex = pVertex;
	new->ppAdjEdge = ppAdjEdge;
	new->maxVertexCount = maxVertexCount;
	new->currentVertexCount = 0;
	new->currentEdgeCount = 0;
	new->graphType = GRAPH_UNDIRECTED;
	return (new);
}
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount)
{
	LinkedGraph *new;

	new = createLinkedGraph(maxVertexCount);
	if (!new)
		return (0);
	new->graphType = GRAPH_DIRECTED;
	return (new);
}

void deleteLinkedGraph(LinkedGraph* pGraph)
{
	if (!pGraph)
		return ;
	free(pGraph->pVertex);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

int getEdgeCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentEdgeCount);
}

int getVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->currentVertexCount);
}

int getMaxVertexCountLG(LinkedGraph* pGraph)
{
	return (pGraph->maxVertexCount);
}

int getGraphTypeLG(LinkedGraph* pGraph)
{
	return (pGraph->graphType);
}

int isEmptyLG(LinkedGraph* pGraph)
{
	if (!pGraph)
		return (0);
	return (pGraph->currentVertexCount == 0);
}

int addVertexLG(LinkedGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
	if (vertexID < pGraph->maxVertexCount && pGraph->pVertex[vertexID] == NOT_USED)
	{
		pGraph->pVertex[vertexID] = USED;
		pGraph->currentVertexCount++;
	}
	else
		return (0);
	return (1);
}

int checkVertexValid(LinkedGraph* pGraph, int vertexID)
{
	return (pGraph->pVertex[vertexID] == USED);
}

int is_exist(LinkedList *list, int data)
{
	ListNode *node;
	int i;

	i = 0;
	node = &(list->headerNode);
	while (i < list->currentElementCount)
	{
		if (node->data == data)
			return (i);
		i++;
		node = node->pLink;
	}
	return (-1);
}


int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	LinkedList *temp_list;
	ListNode *temp;
	ListNode temp_add;

	if (!pGraph)
		return (0);
	if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
	{
		temp_list = pGraph->ppAdjEdge[fromVertexID];
		temp = &(temp_list->headerNode);
		while(temp)
		{
			if (is_exist(temp_list, toVertexID) != -1)
				break ;
			if (!temp->pLink)
			{
				temp_add.data = toVertexID;
				temp_add.pLink = 0;
				addLLElement(temp_list, temp_list->currentElementCount, temp_add);
				break ;
			}
			temp = temp->pLink;
		}
		pGraph->currentEdgeCount++;
		printf("test here\n");
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			temp_list = pGraph->ppAdjEdge[toVertexID];
			temp = &(temp_list->headerNode);
			while(temp)
			{
				if (is_exist(temp_list, fromVertexID) != -1)
					break ;
				if (!temp->pLink)
				{
					temp_add.data = fromVertexID;
					temp_add.pLink = 0;
					addLLElement(temp_list, temp_list->currentElementCount, temp_add);
					break ;
				}				
				temp = temp->pLink;
			}				
			pGraph->currentEdgeCount++;
		}
	}
	return (1);
}

// weigth를 어디다 넣어야 할지 모르겠음... vertax에??
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

int removeVertexLG(LinkedGraph* pGraph, int vertexID)
{
	ListNode *temp;
	LinkedList *temp_list;
	int			is_ex;

	if (!pGraph)
		return (0);
	is_ex = 0;
	if (pGraph->pVertex[vertexID] == USED)
	{
		for (int i = 0; i < pGraph->maxVertexCount; i ++)
		{
			temp_list = pGraph->ppAdjEdge[i];
			temp = &(temp_list->headerNode);
			is_ex = is_exist(temp_list, vertexID);
			if (is_ex != -1)
				removeLLElement(temp_list, is_ex);
		}
		pGraph->pVertex[vertexID] = NOT_USED;
		pGraph->currentVertexCount--;
	}
	else
		return (0);
	return (1);
}

int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID)
{
	ListNode *temp;
	LinkedList *temp_list;
	int			is_ex;

	if (!pGraph)
		return (0);
	is_ex = 0;
	if (pGraph->pVertex[fromVertexID] == USED)
	{
		temp_list = pGraph->ppAdjEdge[fromVertexID];
		temp = temp_list->headerNode.pLink;
		is_ex = is_exist(temp_list, toVertexID);
		if (is_ex != -1)
			removeLLElement(temp_list, is_ex);
		pGraph->currentEdgeCount--;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			temp_list = pGraph->ppAdjEdge[toVertexID];
			temp = temp_list->headerNode.pLink;
			is_ex = is_exist(temp_list, fromVertexID);
			if (is_ex != -1)
				removeLLElement(temp_list, is_ex);
		}
	}
	else
		return (0);
	return (1);
}

void deleteGraphNode(LinkedList* pList, int delVertexID)
{
	free(&(pList->headerNode));
	free(pList);
}

int findGraphNodePosition(LinkedList* pList, int vertexID); // 뭔지를 모르겠음

void displayLinkedGraph(LinkedGraph* pGraph)
{
	ListNode *temp;
	LinkedList *temp_list;

	if (!pGraph)
		return ;
	printf("maxVertax : %d\n",pGraph->maxVertexCount);
	printf("currentVertax : %d\n",pGraph->currentVertexCount);	
	printf("index  : ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("[%d] ",i);
	}
	printf("\n");
	printf("vertax : ");
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		printf("[%d] ",pGraph->pVertex[i]);
	}
	printf("\n=========================\n");
	
	
	for (int i = 0; i < pGraph->maxVertexCount; i++)
	{
		temp_list = pGraph->ppAdjEdge[i];
		temp = temp_list->headerNode.pLink;
		printf("Edge[%d]: ",i);
		while (temp)
		{
			printf("[%d] ", temp->data);
			temp = temp->pLink;
		}
		printf("\n");
	}
	printf("\n");
}