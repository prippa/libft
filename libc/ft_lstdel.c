/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;
	t_list	*tmp;

	l = *alst;
	while (l)
	{
		tmp = l;
		del(l->content, l->content_size);
		l = l->next;
		free(tmp);
	}
	*alst = NULL;
}
