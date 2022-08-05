/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayDoublyList.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:33:27 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 18:26:27 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>

void displayDoublyList(DoublyList* pList)
{
	DoublyListNode	*temp;
	int				cnt;

	if (pList->currentElementCount == 0)
		printf("DoublyList is Null =====================\n");
	else
	{
		cnt = 0;
		temp = &pList->headerNode;
		printf("DoublyList currentElementCount : %d\n", pList->currentElementCount);
		while (cnt < pList->currentElementCount)
		{
			printf("DoublyList Index[%d]_degree : %d, pre : %d, next : %d \n", cnt, temp->pRLink->degree, temp->degree, temp->pRLink->pRLink->degree);
			printf("DoublyList Index[%d]_coef : %f, pre : %f, next : %f \n", cnt, temp->pRLink->coef, temp->coef, temp->pRLink->pRLink->coef);
			temp = temp->pRLink;
			cnt++;
		}
	}
}
