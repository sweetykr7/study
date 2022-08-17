#include "arrayqueue.h"
#include <stdlib.h>

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