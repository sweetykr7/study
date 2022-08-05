/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deleteArrayList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:48:32 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/25 14:49:59 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"
#include <stdlib.h>

void	deleteArrayList(ArrayList *pList)
{
	if (!pList)
		return ;
	free(pList->pElement);
	free(pList);
}
