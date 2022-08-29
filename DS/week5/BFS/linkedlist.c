
#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

LinkedList	*createLinkedList(void)
{
	LinkedList	*head;

	head = malloc(sizeof(LinkedList));
	if (!head)
		return (0);
	head->currentElementCount = 0;
	head->headerNode.data = 0;
	head->headerNode.pLink = 0;
	return (head);
}


int	addLLElement(LinkedList *pList, int position, ListNode element)
{
	ListNode	*pre;
	ListNode	*new;
	int			cnt;

	if (position < 0 || position > pList->currentElementCount)
	{
		printf("position error\n");
		return (-1);
	}
	new = malloc(sizeof(ListNode));
	if (!new)
	{
		printf("malloc error\n");
		return (-1);
	}
	*new = element;
	new->pLink = 0;
	if (position == 0)
	{
		if (pList->currentElementCount == 0)
		{
			pList->headerNode.pLink = new;
			pList->headerNode.pLink->pLink = 0;
		}
		else
		{
			pre = pList->headerNode.pLink;
			new->pLink = pre;
			pList->headerNode.pLink = new;
		}
		pList->currentElementCount++;
		return (0);
	}
	pre = pList->headerNode.pLink;
	cnt = 1;
	while (cnt < position)
	{
		pre = pre->pLink;
		cnt++;
	}
	new->pLink = pre->pLink;
	pre->pLink = new;
	pList->currentElementCount++;
	return (position);
}


int	removeLLElement(LinkedList *pList, int position)
{
	ListNode	*pre_temp;
	ListNode	*curr_temp;
	ListNode	*next_temp;
	int			cnt;

	pre_temp = pList->headerNode.pLink;
	cnt = 1;
	while (cnt < position)
	{
		pre_temp = pre_temp->pLink;
		cnt++;
	}
	curr_temp = pre_temp->pLink;
	if (pre_temp->pLink->pLink)
		next_temp = pre_temp->pLink->pLink;
	else
		next_temp = 0;
	pre_temp->pLink = next_temp;
	free(curr_temp);
	pList->currentElementCount--;
	return (position);
}