/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:32:47 by prippa            #+#    #+#             */
/*   Updated: 2017/10/26 16:32:58 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *h_tmp;
	const char *n_tmp;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			h_tmp = haystack;
			n_tmp = needle;
			while (*h_tmp != '\0' && *h_tmp == *n_tmp)
			{
				++h_tmp;
				++n_tmp;
			}
			if (*n_tmp == '\0')
				return ((char *)haystack);
		}
		++haystack;
	}
	return (NULL);
}
