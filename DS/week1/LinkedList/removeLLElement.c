/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeLLElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:59:48 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 11:18:58 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

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
