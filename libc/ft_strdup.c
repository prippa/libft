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

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	char		*tmp;

	tmp = (char *)s1;
	while (*tmp != '\0')
		++tmp;
	if (!(str = (char *)malloc(sizeof(char) * ((tmp - s1) + 1))))
		return (NULL);
	tmp = str;
	while ((*tmp++ = *s1++) != '\0')
		;
	return (str);
}
