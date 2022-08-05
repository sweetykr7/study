/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:34:30 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 14:52:33 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	ArrayList		*test_array;
	ArrayListNode	add_array;
	ArrayListNode	*get_array;

	printf("createArrayList =====================\n");
	test_array = createArrayList(8);
	displayArrayList(test_array);
	printf("addALElement =====================\n");
	add_array.data = 1;
	addALElement(test_array, 0, add_array);
	add_array.data = 3;
	addALElement(test_array, 1, add_array);
	add_array.data = -1;
	addALElement(test_array, 0, add_array);
	add_array.data = 10;
	addALElement(test_array, 1, add_array);
	add_array.data = -5;
	addALElement(test_array, 4, add_array);
	printf("isArrayListFull =====================\n");
	if (isArrayListFull(test_array))
		printf("ArrayList is Full\n");
	else
		printf("ArrayList is not full\n");
	displayArrayList(test_array);
	printf("getALElement Index : 0 =====================\n");
	get_array = getALElement(test_array, 0);
	printf("get array is %d\n", get_array->data);
	printf("getArrayListLength =====================\n");
	printf("get ArrayList Length is %d\n", getArrayListLength(test_array));
	printf("removeALElement Index : 1 =====================\n");
	removeALElement(test_array, 1);
	displayArrayList(test_array);
	printf("clearArrayList =====================\n");
	clearArrayList(test_array);
	displayArrayList(test_array);
	printf("deleteArrayList =====================\n");
	deleteArrayList(test_array);
	displayArrayList(test_array);
	//system("leaks arrayList");
	return (0);
}
