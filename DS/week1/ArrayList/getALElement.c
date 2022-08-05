/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getALElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:21:16 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 14:56:59 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>

ArrayListNode	*getALElement(ArrayList *pList, int position)
{
	if (position >= pList->currentElementCount || position < 0)
		printf("pList[%d] is not avaliable area\n", position);
	return (&pList->pElement[position]);
}
