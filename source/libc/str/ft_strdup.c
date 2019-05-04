/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:20:01 by prippa            #+#    #+#             */
/*   Updated: 2017/11/05 13:33:13 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strdup(const char *s1)
{
	char		*new_obj;

	new_obj = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s1) + 1));
	return (ft_strcpy(new_obj, s1));
}
