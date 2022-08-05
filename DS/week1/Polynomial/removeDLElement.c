/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeDLElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:12:13 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 17:41:59 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

int	removeDLElement(DoublyList *pList, int position)
{
	DoublyListNode	*pre_temp;
	DoublyListNode	*curr_temp;
	DoublyListNode	*next_temp;
	int				cnt;

	if (!pList || position < 0 || position >= pList->currentElementCount)
	{
		printf("position error \n");
		return (0);
	}
	pre_temp = &pList->headerNode;
	cnt = 0;

	if (position < (pList->currentElementCount / 2))
	{
		pre_temp = &pList->headerNode;
		cnt = 0;
		while (cnt < position)
		{
			pre_temp = pre_temp->pRLink;
			cnt++;
		}
	}
	else
	{
		pre_temp = pList->headerNode.pLLink;
		cnt = pList->currentElementCount;
		while (cnt > position)
		{
			pre_temp = pre_temp->pLLink;
			cnt--;
		}
	}
	curr_temp = pre_temp->pRLink;
	next_temp = pre_temp->pRLink->pRLink;
	pre_temp->pRLink = next_temp;
	next_temp->pLLink = pre_temp;
	free(curr_temp);
	pList->currentElementCount--;
	return (1);
}
