#include "linkeddeque.h"

DequeNode* peekFrontLD(LinkedDeque* pDeque)
{
	return (pDeque->pFrontNode);
}

DequeNode* peekRearLD(LinkedDeque* pDeque)
{
	return (pDeque->pRearNode);
}

int isLinkedDequeEmpty(LinkedDeque* pDeque)
{
	if (!pDeque)
		return (TRUE);
	if (!pDeque->pFrontNode || !pDeque->pRearNode)
		return (TRUE);
	return (FALSE);
} 


int insertRearLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode*	node;

	node = malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	*node = element;
	if (pDeque->pFrontNode == 0 || pDeque->pRearNode == 0)
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
		node->pRLink = 0;
		node->pLLink = 0;
	}
	else
	{
		node->pLLink = pDeque->pRearNode;
		pDeque->pRearNode->pRLink = node;
		pDeque->pRearNode = node;
		node->pRLink = 0;
	}
	pDeque->currentElementCount++;

	return (TRUE);
}


int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	DequeNode*	node;

	node = malloc(sizeof(DequeNode));
	if (!node)
		return (FALSE);
	*node = element;
	if (pDeque->pFrontNode == 0 || pDeque->pRearNode == 0)
	{
		pDeque->pFrontNode = node;
		pDeque->pRearNode = node;
		node->pRLink = 0;
		node->pLLink = 0;
	}
	else
	{
		node->pRLink = pDeque->pFrontNode;
		pDeque->pFrontNode->pLLink = node;
		pDeque->pFrontNode = node;
		node->pLLink = 0;
	}
	pDeque->currentElementCount++;
	return (TRUE);
}


DequeNode* deleteRearLD(LinkedDeque* pDeque)
{
	DequeNode*	node;

	if (pDeque->currentElementCount == 0)
		return (FALSE);
	node = pDeque->pRearNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
		pDeque->currentElementCount = 0;
		node->pLLink = 0;
		node->pRLink = 0;
		return (node);
	}
	pDeque->pRearNode = pDeque->pRearNode->pLLink;
	node->pLLink = 0;
	pDeque->pRearNode->pRLink = 0;
	pDeque->currentElementCount--;
	return (node);
}


void deleteLinkedDeque(LinkedDeque* pDeque)
{
	while (!isLinkedDequeEmpty(pDeque))
		free(deleteFrontLD(pDeque));
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque)
{
	DequeNode*	node;

	if (pDeque->currentElementCount == 0)
		return (FALSE);
	node = pDeque->pFrontNode;
	if (pDeque->currentElementCount == 1)
	{
		pDeque->pFrontNode = 0;
		pDeque->pRearNode = 0;
		pDeque->currentElementCount = 0;
		node->pLLink = 0;
		node->pRLink = 0;
		return (node);
	}
	pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
	node->pRLink = 0;
	pDeque->pFrontNode->pLLink = 0;
	pDeque->currentElementCount--;
	return (node);
}


LinkedDeque* createLinkedDeque()
{
	LinkedDeque*	deque;

	deque = malloc(sizeof(LinkedDeque));
	if (!deque)
		return (0);
	return (deque);
}

void clearLinkedDeque(LinkedDeque* pDeque)
{
	deleteLinkedDeque(pDeque);
    free(pDeque);
}
