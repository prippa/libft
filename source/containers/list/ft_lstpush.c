/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:15 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:40:12 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstpush_front(t_list *lst, t_list_elem *new_obj)
{
	new_obj->prev = NULL;
	new_obj->next = lst->start;
	if (lst->start)
		lst->start->prev = new_obj;
	else
		lst->end = new_obj;
	lst->start = new_obj;
	++lst->list_size;
}

void	ft_lstpush_back(t_list *lst, t_list_elem *new_obj)
{
	new_obj->next = NULL;
	new_obj->prev = lst->end;
	if (lst->end)
		lst->end->next = new_obj;
	else
		lst->start = new_obj;
	lst->end = new_obj;
	++lst->list_size;
}
