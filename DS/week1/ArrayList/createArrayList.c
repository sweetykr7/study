/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createArrayList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:38:05 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 14:49:45 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include "stdlib.h"

ArrayList	*createArrayList(int maxElementCount)
{
	ArrayList		*new;
	ArrayListNode	*element;

	if (maxElementCount <= 0)
		return (0);
	new = malloc(sizeof(ArrayList));
	if (!new)
		return (0);
	element = malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!element)
	{
		free(new);
		return (0);
	}
	new->maxElementCount = maxElementCount;
	new->currentElementCount = 0;
	new->pElement = element;
	return (new);
}
