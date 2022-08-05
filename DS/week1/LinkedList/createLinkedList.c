/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createLinkedList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 07:27:01 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 14:57:46 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include <stdlib.h>

LinkedList	*createLinkedList(void)
{
	LinkedList	*head;

	head = malloc(sizeof(LinkedList));
	if (!head)
		return (0);
	head->currentElementCount = 0;
	head->headerNode.data = 0;
	head->headerNode.pLink = 0;
	return (head);
}
