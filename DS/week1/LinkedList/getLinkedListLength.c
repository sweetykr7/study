/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getLinkedListLength.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 08:30:54 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 15:01:19 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdio.h>

int	getLinkedListLength(LinkedList *pList)
{
	if (!pList)
		printf("pList is not available");
	return (pList->currentElementCount);
}
