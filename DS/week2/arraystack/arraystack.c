#include "arraystack.h"

ArrayStack* createArrayStack(int maxElementCount)
{
	ArrayStack	*new;
	node		*node;

	if (maxElementCount <= 0)
		return (FALSE);
	new = malloc(sizeof(ArrayStack));
	if (!new)
		return (FALSE);
	node = malloc(sizeof(node) * maxElementCount);
	if (!node)
		return (FALSE);
	new->maxElementCount = maxElementCount;
	new->currentElementCount = 0;
	new->pElement = node;
	return (new);
}

int pushLS(ArrayStack* pStack, node element)
{
	if (!pStack)
		return (FALSE);
	if (pStack->maxElementCount == pStack->currentElementCount)
	{
		realloc(pStack->pElement, pStack->maxElementCount * 2);
		pStack->maxElementCount = pStack->maxElementCount * 2;
	}
	pStack->pElement[pStack->currentElementCount] = element;
	pStack->currentElementCount++;
	return (TRUE);
}

node* popLS(ArrayStack* pStack)
{
	if (!pStack || pStack->currentElementCount == 0)
		return (FALSE);
	pStack->currentElementCount--;
	return (pStack->pElement[pStack->currentElementCount]);
}

node* peekLS(ArrayStack* pStack)
{
	if (!pStack || pStack->currentElementCount == 0)
		return (FALSE);
	return (pStack->pElement[pStack->currentElementCount - 1]);
}

void deleteArrayStack(ArrayStack* pStack)
{
	if (!pStack)
		return (FALSE);
	if (pStack->pElement)
		free(pStack->pElement);
	free(pStack);
}

int isArrayStackFull(ArrayStack* pStack)
{
	return (pStack->currentElementCount == pStack->maxElementCount);
}

int isArrayStackEmpty(ArrayStack* pStack)
{
	return (pStack->currentElementCount == 0);
}