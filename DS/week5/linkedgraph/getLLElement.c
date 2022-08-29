/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLLElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:16:19 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 15:00:09 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

ListNode	*getLLElement(LinkedList *pList, int position)
{
	ListNode	*temp;

	temp = &pList->headerNode;
	if (position < 0 || position > pList->currentElementCount)
		printf("position error\n");
	while (position + 1 > 0)
	{
		if (!temp)
		{
			printf("position error\n");
			return (0);
		}
		temp = temp->pLink;
		position--;
	}
	return (temp);
}
