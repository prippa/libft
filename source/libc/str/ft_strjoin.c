/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:54:41 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:54:54 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_obj;
	size_t	s1_size;

	s1_size = ft_strlen(s1);
	new_obj = (char *)ft_memalloc(sizeof(char) * (s1_size + ft_strlen(s2) + 1));
	ft_strcpy(new_obj, s1);
	ft_strcpy(new_obj + s1_size, s2);
	return (new_obj);
}
