/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:10:48 by prippa            #+#    #+#             */
/*   Updated: 2018/10/06 16:10:49 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strdup_free(char **dst, const char *src)
{
	char *tmp;

	tmp = *dst;
	*dst = ft_strdup(src);
	ft_strdel(&tmp);
	return (*dst);
}
