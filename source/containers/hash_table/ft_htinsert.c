/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htinsert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:55:42 by prippa            #+#    #+#             */
/*   Updated: 2019/04/05 13:55:43 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

void		ft_htinsert(t_hash_table *ht, const t_ht_elem *elem)
{
	ft_ht_insert_logic(ht, elem, false);
}

void		ft_htinsert_ref(t_hash_table *ht, const t_ht_elem *elem)
{
	ft_ht_insert_logic(ht, elem, true);
}
