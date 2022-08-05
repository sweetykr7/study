/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayArrayList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:23:17 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/22 07:10:22 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

void	displayArrayList(ArrayList *pList)
{
	int	i;

	i = -1;
	if (pList->currentElementCount != 0)
	{
		printf("maxElementCount : %d \n", pList->maxElementCount);
		printf("currentElementCount : %d \n", pList->currentElementCount);
		while (++i < pList->currentElementCount)
			printf("pList[%d] : %d \n", i, pList->pElement[i].data);
	}
	else
		printf("ArrayList is Null\n");
}
