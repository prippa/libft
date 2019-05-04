/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_right_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 13:57:34 by prippa            #+#    #+#             */
/*   Updated: 2019/03/30 13:57:36 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"
#include "ft_is.h"

size_t	ft_get_right_word(const char *line, size_t pos, size_t end)
{
	size_t n;

	n = 0;
	while (pos < end)
	{
		if (ft_isalnum(line[pos]))
		{
			++n;
			while (++pos < end && ft_isalnum(line[pos]))
				++n;
			return (n);
		}
		++pos;
		++n;
	}
	return (n);
}
