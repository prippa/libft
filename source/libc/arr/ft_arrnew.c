/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 15:44:21 by prippa            #+#    #+#             */
/*   Updated: 2018/02/26 15:44:26 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

char	**ft_arrnew(size_t y, size_t x, int32_t c)
{
	char	**arr;
	size_t	x_len;

	arr = (char **)ft_memalloc(sizeof(char *) * (y + 1));
	x_len = (sizeof(char) * (x + 1));
	while (y--)
	{
		arr[y] = (char *)ft_memalloc(x_len);
		ft_memset(arr[y], c, x_len - 1);
	}
	return (arr);
}
