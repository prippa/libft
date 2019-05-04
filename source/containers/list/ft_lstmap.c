/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:55 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 11:56:21 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

t_list	ft_lstmap(t_list *lst, t_lst_map_f f)
{
	t_list		new_list;
	t_list_elem	*elem;
	t_list_elem	*start;

	start = lst->start;
	ft_bzero(&new_list, sizeof(t_list));
	new_list.start = f(start);
	elem = new_list.start;
	while (start->next)
	{
		elem->next = f(start->next);
		elem = elem->next;
		start = start->next;
	}
	return (new_list);
}
