#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

// typedef struct HeapNodeType
// {
// 	int	key;
// }	HeapNode;

// typedef struct HeapType
// {
// 	int			maxCount;
// 	int			currentCount;
// 	HeapNode	*pElement;
// }	Heap;

Heap*		createHeap(int maxCount)
{
	Heap		*new;
	HeapNode	*node;

	new = malloc(sizeof(Heap));
	if (!new)
		return (0);
	node = malloc(sizeof(HeapNode) * (maxCount + 1));
	if (!node)
	{
		free(new);
		return (0);
	}
	new->maxCount = maxCount;
	new->currentCount = 0;
	new->pElement = node;
	return (new);
}


int			isHeapFull(Heap *pHeap)
{
	return (pHeap->maxCount == pHeap->currentCount);
}

int			isHeapEmpty(Heap *pHeap)
{
	return (pHeap->currentCount == 0);
}

int			insertMaxHeap(Heap *pHeap, HeapNode element)
{
	int	i;
	int	p_i;

	if (!pHeap || isHeapFull(pHeap))
		return (0);
	pHeap->currentCount++;
	i = pHeap->currentCount;
	p_i = i / 2;
	while (i > 1 && (element.key >= pHeap->pElement[p_i].key))
	{
		pHeap->pElement[i].key = pHeap->pElement[p_i].key; 
		i = i / 2;
		p_i = i / 2;
	}
	pHeap->pElement[i] = element;
	return (1);
}

int			insertMinHeap(Heap *pHeap, HeapNode element)
{
	int	i;
	int	p_i;

	if (!pHeap && isHeapFull(pHeap))
		return (0);
	pHeap->currentCount++;
	i = pHeap->currentCount;
	p_i = i / 2;
	while (i > 1 && (element.key <= pHeap->pElement[p_i].key))
	{
		pHeap->pElement[i].key = pHeap->pElement[p_i].key; 
		i = i / 2;
		p_i = i / 2;
	}
	pHeap->pElement[i] = element;
	return (1);
}

int			deleteMaxHeapNode(Heap *pHeap)
{
	int	i;
	int	left_idx;
	int	right_idx;
	int	large_idx;
	int	temp;

	if (!pHeap || isHeapEmpty(pHeap))
		return (0);
	i = 1;
	pHeap->pElement[i].key = pHeap->pElement[pHeap->currentCount].key;
	pHeap->currentCount--;
	while (i < pHeap->currentCount)
	{
		left_idx = i * 2;
		right_idx = i * 2 + 1;
		large_idx = left_idx;
		if (right_idx <= pHeap->currentCount && pHeap->pElement[right_idx].key > pHeap->pElement[left_idx].key)
			large_idx = right_idx;
		if (pHeap->pElement[large_idx].key > pHeap->pElement[i].key)
		{
			temp = pHeap->pElement[i].key;
			pHeap->pElement[i].key = pHeap->pElement[large_idx].key;
			pHeap->pElement[large_idx].key = temp;
		}
		i = large_idx;
	}
	return (1);
}

int			deleteMinHeapNode(Heap *pHeap)
{
	int	i;
	int	left_idx;
	int	right_idx;
	int	small_idx;
	int	temp;

	if (!pHeap || isHeapEmpty(pHeap))
		return (0);
	i = 1;
	pHeap->pElement[i].key = pHeap->pElement[pHeap->currentCount].key;
	pHeap->currentCount--;
	while (i < pHeap->currentCount)
	{
		left_idx = i * 2;
		right_idx = i * 2 + 1;
		small_idx = left_idx;
		if (right_idx <= pHeap->currentCount && pHeap->pElement[right_idx].key < pHeap->pElement[left_idx].key)
			small_idx = right_idx;
		if (pHeap->pElement[small_idx].key < pHeap->pElement[i].key)
		{
			temp = pHeap->pElement[i].key;
			pHeap->pElement[i].key = pHeap->pElement[small_idx].key;
			pHeap->pElement[small_idx].key = temp;
		}
		i = small_idx;
	}
	return (1);
}

void		deleteHeap(Heap *pHeap)
{
	if (!pHeap)
		return ;
	free(pHeap->pElement);
	free(pHeap);
}
HeapNode	*getMaxHeapNode(Heap *pHeap)
{
	return (pHeap->pElement);
}

HeapNode	*getMinHeapNode(Heap *pHeap)
{
	return (pHeap->pElement);
}

void		displayHeap(Heap *pHeap)
{
	int i;

	i = 1;
	while (i <= pHeap->currentCount)
	{
		printf("Heap[%d] : %d \n", i, pHeap->pElement[i].key);
		i++;
	}
}