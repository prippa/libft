/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:52:52 by prippa            #+#    #+#             */
/*   Updated: 2017/11/06 13:52:55 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_put.h"
#include "ft_str.h"
#include "ft_def.h"

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
	ft_putchar(ENDL);
}
