/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkeddeque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 09:05:47 by sooyokim          #+#    #+#             */
/*   Updated: 2022/08/08 09:19:34 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct DequeNodeType
// {
// 	char data;
// 	struct DequeNodeType* pRLink;
// 	struct DequeNodeType* pLLink;
// } DequeNode;

// typedef struct LinkedDequeType
// {
// 	int currentElementCount;
// 	DequeNode* pFrontNode;
// 	DequeNode* pRearNode;		
// } LinkedDeque;

LinkedDeque* createLinkedDeque()
{
	LinkedDeque	*new;

	new = malloc(sizeof(LinkedDeque));
	if (!new)
		return (0);
	new->currentElementCount = 0;
	new->pFrontNode = 0;
	new->pRearNode = 0;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element)
{
	if (pDeque->currentElementCount == 0)
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element);
DequeNode* deleteFrontLD(LinkedDeque* pDeque);
DequeNode* deleteRearLD(LinkedDeque* pDeque);
DequeNode* peekFrontLD(LinkedDeque* pDeque);
DequeNode* peekRearLD(LinkedDeque* pDeque);
void deleteLinkedDeque(LinkedDeque* pDeque);
int isLinkedDequeFull(LinkedDeque* pDeque);
int isLinkedDequeEmpty(LinkedDeque* pDeque);

int main(int ac, char **av)
{
	return (0);
}