/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createDoublyList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:45:26 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 13:25:54 by sooyokim         ###   ########.fr       */
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
	new->headerNode.data = 0;
	new->headerNode.pLLink = &new->headerNode;
	new->headerNode.pRLink = &new->headerNode;
	return (new);
}
