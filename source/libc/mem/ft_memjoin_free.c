/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:59:59 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 13:00:00 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_memjoin_free(void **dst, const void *src,
			size_t dstsize, size_t srcsize)
{
	void *tmp;

	tmp = *dst;
	*dst = ft_memalloc(sizeof(void) * (dstsize + srcsize));
	ft_memcpy(*dst, tmp, dstsize);
	ft_memcpy(*dst + dstsize, src, srcsize);
	ft_memdel(&tmp);
	return (*dst);
}
