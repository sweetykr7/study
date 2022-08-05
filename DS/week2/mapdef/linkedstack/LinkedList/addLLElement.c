/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addLLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:46:25 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 10:49:37 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

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
