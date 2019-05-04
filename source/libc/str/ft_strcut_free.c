/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 12:25:37 by prippa            #+#    #+#             */
/*   Updated: 2019/03/23 12:25:39 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strcut_free(char **dst, size_t start, size_t end)
{
	char	*tmp;

	tmp = *dst;
	*dst = (char *)ft_memalloc((ft_strlen(*dst) - (end - start)) + 1);
	ft_strncpy(*dst, tmp, start);
	ft_strcpy(*dst + start, tmp + end);
	ft_strdel(&tmp);
	return (*dst);
}
