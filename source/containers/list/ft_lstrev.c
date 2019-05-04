/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 18:41:02 by prippa            #+#    #+#             */
/*   Updated: 2019/01/12 18:41:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_lstrev_next(t_list *lst)
{
	t_list_elem *prev;
	t_list_elem *current;
	t_list_elem *next;

	prev = NULL;
	current = lst->start;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	lst->start = prev;
}

void		ft_lstrev(t_list *lst)
{
	t_list_elem	*current;
	t_list_elem	*prev;
	t_list_elem	*next;

	prev = NULL;
	current = lst->end;
	while (current)
	{
		next = current->prev;
		current->prev = prev;
		prev = current;
		current = next;
	}
	lst->end = prev;
	ft_lstrev_next(lst);
}
