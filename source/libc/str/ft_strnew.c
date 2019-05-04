/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:43:39 by prippa            #+#    #+#             */
/*   Updated: 2017/11/03 16:43:40 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

char	*ft_strnew(size_t size)
{
	char *new_obj;

	new_obj = (char*)ft_memalloc(sizeof(char) * (size + 1));
	return (new_obj);
}
