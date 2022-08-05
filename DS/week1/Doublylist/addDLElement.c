/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addDLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:09:16 by sooyokim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 18:16:31 by sooyokim         ###   ########.fr       */
=======
/*   Updated: 2022/07/29 14:29:28 by sooyokim         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	DoublyListNode	*new;
	DoublyListNode	*pre;
	int				curr;

	if (!pList || position < -1 || position > pList->currentElementCount)
	{
		printf("position error \n");
		return (0);
	}
	new = malloc(sizeof(DoublyListNode));
	if (!new)
		return (0);
	*new = element;
	pre = &pList->headerNode;
	if (position == -1)
	{
		new->pLLink = pList->headerNode.pLLink;
		pList->headerNode.pLLink->pRLink = new;
		new->pRLink = &pList->headerNode;
		pList->headerNode.pLLink = new;
		pList->currentElementCount++;
		return (1);
	}	
	curr = 0;
	while (curr < position)
	{
		pre = pre->pRLink;
		curr++;
	}
	new->pRLink = pre->pRLink;
	new->pLLink = pre;
	new->pRLink->pLLink = new;
	pre->pRLink = new;
	pList->currentElementCount++;
	return (1);

}

