/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_left_word.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:57:27 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:57:29 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "ft_is.h"

size_t	ft_get_left_word(const char *line, size_t pos, size_t start)
{
	size_t n;

	n = 1;
	while (--pos > start)
	{
		if (ft_isalnum(line[pos]))
		{
			while (--pos >= start && ft_isalnum(line[pos]))
			{
				++n;
				if (pos == start)
					return (n);
			}
			return (n);
		}
		++n;
	}
	return (n);
}
