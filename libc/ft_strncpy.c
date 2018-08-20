/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 19:18:01 by prippa            #+#    #+#             */
/*   Updated: 2017/10/30 19:18:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *tmp;

	tmp = dst;
	while (len != 0)
	{
		if (!(*tmp++ = *src++))
		{
			while (--len != 0)
				*tmp++ = '\0';
			break ;
		}
		len--;
	}
	return (dst);
}
