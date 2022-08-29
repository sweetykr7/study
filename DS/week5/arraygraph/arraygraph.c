#include "arraygraph.h"
#include <stdio.h>
#include <stdlib.h>

// 1-Undirected, 2-Directed
ArrayGraph* createArrayGraph(int maxVertexCount)
{
	ArrayGraph *new;
	int **ppAdjEdge;		//   간선 저장을 위한 배열 포인터
	int *pVertex;			//  노드 저장을 위한 배열 포인터

	new = malloc(sizeof(ArrayGraph));
	if (!new)
		return (0);
	ppAdjEdge = malloc(sizeof(int *) * maxVertexCount);
	if (!ppAdjEdge)
		return (0);
	for (int i = 0; i < maxVertexCount; i ++)
	{
		ppAdjEdge[i] = malloc(sizeof(int) * maxVertexCount);
		if (!ppAdjEdge[i])
			return (0);
		//ppAdjEdge[i] = 0;
	}
	pVertex = malloc(sizeof(int) * maxVertexCount);
	if (!pVertex)
		return (0);
	new->maxVertexCount = maxVertexCount;
	new->currentVertexCount = 0;
	new->graphType = GRAPH_UNDIRECTED;
	new->ppAdjEdge = ppAdjEdge;
	new->pVertex = pVertex;
	return (new);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount)
{
	ArrayGraph *new;
	
	new = createArrayGraph(maxVertexCount);
	new->graphType = GRAPH_DIRECTED;
	return (new);
}

void deleteArrayGraph(ArrayGraph* pGraph)
{
	free(pGraph->ppAdjEdge);
	free(pGraph->pVertex);
	free(pGraph);
}

int isEmptyAG(ArrayGraph* pGraph)
{
	return (pGraph->currentVertexCount == 0);
}

int addVertexAG(ArrayGraph* pGraph, int vertexID)
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

int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (0);
	if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
		}
	}
	return (1);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight)
{
	if (!pGraph)
		return (0);
	if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
		}
	}
	return (1);
}

int checkVertexValid(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
	return (pGraph->pVertex[vertexID]);
}

int removeVertexAG(ArrayGraph* pGraph, int vertexID)
{
	if (!pGraph)
		return (0);
	if (pGraph->pVertex[vertexID] == USED)
	{
		for (int i = 0; i < pGraph->maxVertexCount; i ++)
		{
			pGraph->ppAdjEdge[vertexID][i] = 0;
			pGraph->ppAdjEdge[i][vertexID] = 0;
		}
		pGraph->pVertex[vertexID] = NOT_USED;
		pGraph->currentVertexCount--;
	}
	else
		return (0);
	return (1);
}

int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID)
{
	if (!pGraph)
		return (0);
	if (pGraph->pVertex[fromVertexID] == USED && pGraph->pVertex[toVertexID] == USED)
	{
		pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
		if (pGraph->graphType == GRAPH_UNDIRECTED)
		{
			pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
		}
	}
	return (1);
}

void	deleteAG(ArrayGraph *pGraph)
{
	if (!pGraph)
		return ;
	free(pGraph->pVertex);
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->ppAdjEdge);
	free(pGraph);
}

void displayArrayGraph(ArrayGraph* pGraph)
{
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
		printf("Edge[%d]: ",i);
		for (int j = 0; j < pGraph->maxVertexCount; j++)
		{
			printf("[%d] ",pGraph->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}