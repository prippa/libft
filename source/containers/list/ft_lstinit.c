/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:01:36 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:01:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

void	ft_lstinit(t_list *lst, t_delptr del_list_func)
{
	ft_bzero(lst, sizeof(t_list));
	lst->del = del_list_func;
}
