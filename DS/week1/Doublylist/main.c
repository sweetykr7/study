/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:34:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 18:04:28 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>



// #include "createDoublyList.c"
// #include "addDLElement.c"
// #include "removeDLElement.c"
// #include "getDLElement.c"
// #include "clearDoublyList.c"
// #include "getDoublyListLength.c"
// #include "deleteDoublyList.c"
// #include "displayDoublyList.c"




int	main(void)
{
	DoublyList		*head;
	DoublyListNode	node1;
	DoublyListNode	node2;
	DoublyListNode	node3;
	DoublyListNode	node4;
	DoublyListNode	node5;

	printf("createDoublyList =====================\n");
	head = createDoublyList();	
	printf("addDLElement =====================\n");
	node1.data = 10;
	addDLElement(head, 0, node1);
	node2.data = 3;
	addDLElement(head, 1, node2);
	node3.data = -1;
	addDLElement(head, 0, node3);
	node4.data = 5;
	addDLElement(head, 3, node4);
	node5.data = 20;
	addDLElement(head, -1, node5);
	node5.data = -13;
	addDLElement(head, -1, node5);
	printf("pass test\n");
	node5.data = 15;
	addDLElement(head, 7, node5);
	displayDoublyList(head);


	printf("getDoublyListLength =====================\n");
	printf("Length : %d\n", getDoublyListLength(head));
	printf("getDLElement =====================\n");
	printf("getDLElement[1] : %d\n", getDLElement(head, 1)->data);
	printf("getDLElement[3] : %d\n", getDLElement(head, 3)->data);
	printf("removeDLElement Index 0 =====================\n");
	removeDLElement(head, 0);
	displayDoublyList(head);
	printf("removeDLElement Index 2 =====================\n");
	removeDLElement(head, 2);
	displayDoublyList(head);
	printf("clearDoublyList =====================\n");
	clearDoublyList(head);
	displayDoublyList(head);
	printf("deleteLinkedList =====================\n");
	deleteDoublyList(head);
	displayDoublyList(head);
	return (0);
}
