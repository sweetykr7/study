#include "linkedstack.h"


int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	if (!pStack)
		return (-1);
	return (pStack->currentElementCount == 0);
}

LinkedStack* createLinkedStack()
{
	LinkedStack	*head;

	head = malloc(sizeof(LinkedStack));
	if (!head)
		return (0);
	head->currentElementCount = 0;
	head->final_y = 0;
	head->pTopElement = 0;
	return (head);
}

int pushLS(LinkedStack* pStack, StackNode element)
{
	StackNode *new;
	StackNode *pre;

	if (!pStack)
	{
		printf("pStack isn't working\n");
		return (FALSE);
	}
	new = malloc(sizeof(StackNode));
	if (!new)
		return (FALSE);
	*new = element;
	pre = pStack->pTopElement;
	pStack->pTopElement = new;
	new->pLink = pre;
	pStack->currentElementCount++;
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *res;
	StackNode *next;
	
	if (pStack->currentElementCount == 0 || !pStack)
	{
		printf("pop is not available \n");
		return (FALSE);
	}
	res = pStack->pTopElement;
	next = pStack->pTopElement->pLink;
	res->pLink = 0;
	pStack->pTopElement = next;
	pStack->currentElementCount--;
	return (res);
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (pStack->currentElementCount == 0 || !pStack)
	{
		printf("peekLS is not available \n");
		return (FALSE);
	}
	return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack* pStack)
{
	StackNode	*curr;

	if (!pStack)
		return ;
	curr = pStack->pTopElement;
	while (curr)
	{
		free(curr);
		curr = curr->pLink;
	}
	free(pStack);
}

void pushLS_ALL(LinkedStack *a, LinkedStack *b)
{
	StackNode *temp;

	if (!a || ! b)
		return ;
	while (!isLinkedStackEmpty(b))
	{
		temp = popLS(b);
		pushLS(a, *temp);
	}
}

void displayStack(LinkedStack *pStack)
{
	int	cnt;
	StackNode *temp;

	if (pStack->currentElementCount == 0 || !pStack)
	{
		printf("No data===================\n");
		return ;
	}
	cnt = 0;
	temp = pStack->pTopElement;
	while (cnt < pStack->currentElementCount && temp)
	{
		printf("stack idx[%d] (x : %d, y : %d)\n", cnt, temp->root.x, temp->root.y);
		temp = temp->pLink;
		cnt++;
	}
}
