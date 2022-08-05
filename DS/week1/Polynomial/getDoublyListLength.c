/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getDoublyListLength.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:22:02 by sooyokim          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/07/27 11:23:21 by sooyokim         ###   ########.fr       */
=======
/*   Updated: 2022/07/29 14:44:31 by sooyokim         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdio.h>

int	getDoublyListLength(DoublyList *pList)
{
	if (!pList)
	{
		printf("pList is not avaliable");
		return (0);
	}
	return (pList->currentElementCount);
}
