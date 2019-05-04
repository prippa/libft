/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:08:20 by prippa            #+#    #+#             */
/*   Updated: 2019/02/27 17:08:22 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strsub_free(char **s, uint32_t start, size_t len)
{
	char	*tmp;

	if (!s || !*s)
		return (NULL);
	tmp = *s;
	*s = (char *)ft_memalloc(sizeof(char) * (len + 1));
	ft_strncpy(*s, tmp + start, len);
	ft_strdel(&tmp);
	return (*s);
}
