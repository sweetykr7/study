/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getArrayListLength.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sooyokim <sooyokim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:30:42 by sooyokim          #+#    #+#             */
/*   Updated: 2022/07/21 17:31:05 by sooyokim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arraylist.h"

int	getArrayListLength(ArrayList *pList)
{
	return (pList->currentElementCount);
}
