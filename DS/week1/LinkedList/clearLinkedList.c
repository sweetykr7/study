/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearLinkedList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:22:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 11:07:46 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>

void	clearLinkedList(LinkedList *pList)
{
	ListNode	*temp;
	ListNode	*clear_temp;

	if (!pList->currentElementCount)
		return ;
	temp = pList->headerNode.pLink;
	while (temp)
	{
		clear_temp = temp;
		clear_temp->pLink = 0;
		temp = temp->pLink;
		free(clear_temp);
	}
	pList->currentElementCount = 0;
}
