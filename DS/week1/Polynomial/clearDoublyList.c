/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearDoublyList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:58:02 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 13:26:48 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

void	clearDoublyList(DoublyList *pList)
{
	DoublyListNode	*temp;
	DoublyListNode	*clr;
	int				cnt;

	if (!pList || pList->currentElementCount == 0)
		return ;
	temp = pList->headerNode.pRLink;
	cnt = 0;
	while (cnt < pList->currentElementCount)
	{
		clr = temp;
		temp = temp->pRLink;
		free(clr);
		cnt++;
	}
	pList->headerNode.pLLink = &pList->headerNode;
	pList->headerNode.pRLink = &pList->headerNode;
	pList->currentElementCount = 0;
}
