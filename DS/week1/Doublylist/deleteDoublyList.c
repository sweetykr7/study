/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteDoublyList.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:57:14 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/27 13:26:56 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <stdlib.h>
#include <stdio.h>

void	deleteDoublyList(DoublyList *pList)
{
	if (!pList)
		return ;
	clearDoublyList(pList);
	free(pList);
}


