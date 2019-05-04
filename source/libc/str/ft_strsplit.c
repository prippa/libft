/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:59:58 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 14:00:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

static size_t	ft_get_size(char const *s, char c)
{
	size_t size;

	size = 0;
	while (*s)
		if (*s != c)
		{
			++size;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	len;

	if (!s || !c)
		return (NULL);
	res = (char **)ft_memalloc(sizeof(char *) * (ft_get_size(s, c) + 1));
	i = -1;
	while (*s)
		if (*s != c)
		{
			len = 0;
			while (*(s + len) && *(s + len) != c)
				++len;
			res[++i] = ft_strsub(s, 0, len);
			s += len;
		}
		else
			++s;
	return (res);
}
