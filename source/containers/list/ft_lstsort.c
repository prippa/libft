/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 12:00:15 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 12:34:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	ft_lstsort_swap(t_list_elem *left, t_list_elem *right)
{
	void	*swap_content;
	size_t	swap_content_size;

	swap_content = left->content;
	swap_content_size = left->content_size;
	left->content = right->content;
	left->content_size = right->content_size;
	right->content = swap_content;
	right->content_size = swap_content_size;
}

void		ft_lstsort(t_list *lst, t_lst_sort_f f)
{
	t_list_elem	*start;
	t_bool		sort;

	if (!lst->start)
		return ;
	sort = true;
	while (sort)
	{
		start = lst->start;
		sort = false;
		while (start->next)
		{
			if (f(start->content, start->next->content))
			{
				ft_lstsort_swap(start, start->next);
				sort = true;
			}
			start = start->next;
		}
	}
}
