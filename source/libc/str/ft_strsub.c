/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:55:18 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:55:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strsub(char const *s, uint32_t start, size_t len)
{
	char	*new_obj;

	if (!s)
		return (NULL);
	new_obj = (char *)ft_memalloc(sizeof(char) * (len + 1));
	return (ft_strncpy(new_obj, s + start, len));
}
