#include "arrayqueue.h"

ArrayQueue*	createArrayQueue(int maxElementCount)
{
	ArrayQueue*	arr;
	ArrayQueueNode*	index;

	arr = malloc(sizeof(ArrayQueue));
	if (!arr)
		return (0);
	index = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!index)
	{
		free(arr);
		return (0);
	}
	arr->pElement = index;
	arr->maxElementCount = maxElementCount;
	return (arr);
}

 void deleteArrayQueue(ArrayQueue* pQueue)
 {
	free(pQueue->pElement);
	pQueue->pElement = 0;
	free(pQueue);
 }


ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode*	node;

	if (pQueue->currentElementCount == 0)
		return (FALSE);
	node = &pQueue->pElement[pQueue->front];
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount--;
	return (node);
}

int	enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue->currentElementCount == pQueue->maxElementCount)
		return (FALSE);
	pQueue->pElement[pQueue->rear] = element;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount++;
	return (TRUE);
}

int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	if ((pQueue->currentElementCount == 0
	|| pQueue->front == pQueue->rear))
		return (TRUE);
	return (FALSE);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	if (pQueue->currentElementCount == pQueue->maxElementCount 
	|| ((pQueue->rear + 1) % pQueue->maxElementCount) == pQueue->front)
		return (TRUE);
	return (FALSE);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	ArrayQueueNode*	node;

	if (pQueue->currentElementCount == 0)
		return (FALSE);
	node = &pQueue->pElement[pQueue->front];
	return (node);
}