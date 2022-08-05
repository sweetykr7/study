/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:52:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 15:06:27 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

int	addALElement(ArrayList *pList, int position, ArrayListNode element)
{
	int	i;

	if (isArrayListFull(pList) || !pList || \
					(position < 0 || position > pList->currentElementCount))
	{
		printf("not avaiable to add(List is Full or position error)\n");
		return (-1);
	}
	else
	{
		i = pList->currentElementCount - 1;
		while (i >= position)
		{
			pList->pElement[i + 1] = pList->pElement[i];
			i--;
		}
		pList->pElement[position] = element;
		pList->currentElementCount++;
		return (position);
	}	
}
