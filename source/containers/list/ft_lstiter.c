/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:38 by prippa            #+#    #+#             */
/*   Updated: 2019/04/30 11:56:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstiter(t_list *lst, t_lst_iter_f f)
{
	t_list_elem *start;

	start = lst->start;
	while (start)
	{
		f(start);
		start = start->next;
	}
}
