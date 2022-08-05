/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polynomial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:31:13 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 19:02:09 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdlib.h>

DoublyList	*polynomial(DoublyList *h1, DoublyList *h2)
{
	DoublyList		*res;
	DoublyListNode	*h1_tmp;
	DoublyListNode	*h2_tmp;
	int				cnt1;
	int				cnt2;

	res = createDoublyList();
	cnt1 = 0;
	cnt2 = 0;
	h1_tmp = h1->headerNode.pRLink;
	h2_tmp = h2->headerNode.pRLink;
	while (cnt1 < h1->currentElementCount && cnt2 < h2->currentElementCount)
	{		
		if (h1_tmp->degree > h2_tmp->degree)
		{
			addPolyNodeLast(res, h1_tmp->coef, h1_tmp->degree);
			h1_tmp = h1_tmp->pRLink;
			cnt1++;
		}		
		else if (h2_tmp->degree > h1_tmp->degree)
		{
			addPolyNodeLast(res, h2_tmp->coef, h2_tmp->degree);
			h2_tmp = h2_tmp->pRLink;
			cnt2++;
		}
		else
		{
			addPolyNodeLast(res, h1_tmp->coef, h1_tmp->degree);
			addPolyNodeLast(res, h2_tmp->coef, h2_tmp->degree);
			h1_tmp = h1_tmp->pRLink;
			h2_tmp = h2_tmp->pRLink;
			cnt1++;
			cnt2++;
		}
	}
	while (cnt1 < h1->currentElementCount)
	{
		addPolyNodeLast(res, h1_tmp->coef, h1_tmp->degree);
		h1_tmp = h1_tmp->pRLink;
		cnt1++;
	}
	while (cnt2 < h2->currentElementCount)
	{
		addPolyNodeLast(res, h2_tmp->coef, h2_tmp->degree);
		h2_tmp = h2_tmp->pRLink;
		cnt2++;
	}
	return (res);
}
