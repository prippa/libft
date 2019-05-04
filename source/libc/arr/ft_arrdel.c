/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 14:29:03 by prippa            #+#    #+#             */
/*   Updated: 2018/01/22 14:29:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_str.h"

void	ft_arrdel(char ***arr)
{
	char **tmp;

	if (arr && *arr)
	{
		tmp = *arr;
		while (*tmp)
			ft_strdel(tmp++);
		ft_memdel((void **)arr);
		*arr = NULL;
	}
}
