/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getDLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:23:39 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 17:36:44 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>

DoublyListNode *getDLElement(DoublyList *pList, int position)
{
	DoublyListNode	*node;
	int				cnt;

	if (!pList || position < -1 || position >= pList->currentElementCount)
	{
		printf("position error \n");
		return (0);
	}
	if (position < (pList->currentElementCount / 2))
	{
		node = pList->headerNode.pRLink;
		cnt = 0;
		while (cnt < position)
		{
			node = node->pRLink;
			cnt++;
		}
	}
	else
	{
		node = pList->headerNode.pLLink;
		cnt = pList->currentElementCount - 1;
		while (cnt > position)
		{
			node = node->pLLink;
			cnt--;
		}
	}
	return (node);
}
