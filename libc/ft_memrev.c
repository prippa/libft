/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:58:49 by prippa            #+#    #+#             */
/*   Updated: 2018/05/26 13:58:50 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrev(void *dst, size_t n)
{
	unsigned char	c;
	unsigned char	*ptr;
	size_t			i;

	if (!n)
		return (dst);
	ptr = (unsigned char *)dst;
	i = 0;
	while (n - 1 > i)
	{
		c = ptr[i];
		ptr[i++] = ptr[n - 1];
		ptr[--n] = c;
	}
	return (dst);
}
