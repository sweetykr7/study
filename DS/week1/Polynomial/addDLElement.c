/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addDLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:09:16 by sooyokim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 18:22:28 by sooyokim         ###   ########.fr       */
=======
/*   Updated: 2022/07/29 15:01:36 by sooyokim         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>

int findEqualDegree(DoublyList *pList, DoublyListNode element)
{
	DoublyListNode	*temp;
	int				cnt;

	temp = &pList->headerNode;
	cnt = 0;
	while (cnt < pList->currentElementCount)
	{
		temp = temp->pRLink;
		if (temp->degree == element.degree)
			return (1);
		cnt++;
	}
	return (0);
}

int	addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
	DoublyListNode	*new;
	DoublyListNode	*pre;
	int				curr;
	int				idx;

	curr = 0;
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
	if (findEqualDegree(pList, element))
	{
		idx = findIndex(pList, element.degree);
		while (curr <= idx)
		{
			pre = pre->pRLink;
			curr++;
		}
		pre->coef = pre->coef + element.coef;
		return (1);
	}
	if (position == -1)
	{
		new->pLLink = pList->headerNode.pLLink;
		pList->headerNode.pLLink->pRLink = new;
		new->pRLink = &pList->headerNode;
		pList->headerNode.pLLink = new;
		pList->currentElementCount++;
		return (1);
	}	
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
<<<<<<< HEAD

=======
>>>>>>> master
}

