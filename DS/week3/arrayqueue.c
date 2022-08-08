/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayqueue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 08:33:45 by sooyokim          #+#    #+#             */
/*   Updated: 2022/08/08 09:11:58 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arrayqueue.h"
#include <stdlib.h>
#include <stdio.h>

// typedef struct ArrayQueueNodeType
// {
// 	char data;
// } ArrayQueueNode;

// typedef struct ArrayQueueType
// {
// 	int maxElementCount;
// 	int currentElementCount;
// 	int front;
// 	int rear;
// 	ArrayQueueNode *pElement;	
// } ArrayQueue;

ArrayQueue* createArrayQueue(int maxElementCount)
{
	ArrayQueue		*new;
	ArrayQueueNode	*node;

	new = malloc(sizeof(ArrayQueue));
	if (!new)
		return (0);
	node = malloc(sizeof(ArrayQueueNode) * maxElementCount);
	if (!node)
		return (0);
	new->pElement = node;
	new->currentElementCount = 0;
	new->maxElementCount = maxElementCount;
	new->front = 0;
	new->rear = 0;
	return (new);
}
int enqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element)
{
	if (pQueue->currentElementCount >= pQueue->maxElementCount)
		return (0);
	pQueue->pElement[(pQueue->rear + 1) % pQueue->maxElementCount] = element;
	pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
	pQueue->currentElementCount++;
	return (1);
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (0);
	pQueue->currentElementCount--;
	pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
	return (&pQueue->pElement[(pQueue->front) % pQueue->maxElementCount - 1]);
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue)
{
	if (pQueue->currentElementCount == 0)
		return (0);
	return (pQueue->pElement);
}
void deleteArrayQueue(ArrayQueue* pQueue)
{
	free(pQueue->pElement);
	free(pQueue);
}

int isArrayQueueFull(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount == pQueue->maxElementCount);
}
int isArrayQueueEmpty(ArrayQueue* pQueue)
{
	return (pQueue->currentElementCount != pQueue->maxElementCount);
}

int	main(int ac, char **av)
{
	ArrayQueue	*new;

	new = createArrayQueue(8);
	return (0);
}
