/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:57:45 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:57:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_is.h"
#include "ft_def.h"

char	*ft_strtrim(char const *s)
{
	char const *start;
	char const *end;

	if (!s)
		return (NULL);
	start = s;
	while (ft_isspace(*start))
		++start;
	end = s;
	while (*end)
		++end;
	--end;
	while (ft_isspace(*end))
		--end;
	if (end < start)
		return (ft_strdup(EMPTY_STR));
	return (ft_strsub(s, (start - s), (end - start + 1)));
}
