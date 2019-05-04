/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:37:46 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

void	ft_lstdel_one(t_list_elem **elem, t_delptr del)
{
	if (!*elem)
		return ;
	if (del)
		del((*elem)->content, (*elem)->content_size);
	ft_memdel((void **)elem);
	*elem = NULL;
}

void	ft_lstdel(t_list *lst)
{
	while (lst->start)
		ft_lstpop_front(lst);
}

void	ft_lstdel_by_obj(t_list *lst, t_list_elem *obj)
{
	if (!obj)
		return ;
	if (!obj->prev)
	{
		lst->start = lst->start->next;
		if (lst->start)
			lst->start->prev = NULL;
		else
			lst->end = NULL;
	}
	else if (!obj->next)
	{
		obj->prev->next = NULL;
		lst->end = obj->prev;
	}
	else
	{
		obj->prev->next = obj->next;
		obj->next->prev = obj->prev;
	}
	ft_lstdel_one(&obj, lst->del);
	--lst->list_size;
}
