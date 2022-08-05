/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeALElement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:15:14 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 14:54:58 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

int	removeALElement(ArrayList *pList, int position)
{
	int	i;

	if (pList->currentElementCount == 0 || position < 0)
	{
		printf("there is no one to remove\n");
		return (-1);
	}
	else
	{
		i = position;
		while (i < pList->currentElementCount)
		{
			pList->pElement[i] = pList->pElement[i + 1];
			i++;
		}
		pList->currentElementCount--;
		return (position);
	}
}
