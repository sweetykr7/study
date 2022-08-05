/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createDoublyList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:45:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 18:24:53 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdlib.h>

DoublyList	*createDoublyList(void)
{
	DoublyList	*new;

	new = malloc(sizeof(DoublyList));
	if (!new)
		return (0);
	new->headerNode.coef = 0;
	new->headerNode.degree = 0;
	new->headerNode.pLLink = &new->headerNode;
	new->headerNode.pRLink = &new->headerNode;
	return (new);
}
