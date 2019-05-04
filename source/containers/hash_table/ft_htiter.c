/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htiter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:00:55 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:01:05 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

void		ft_htiter_all(t_hash_table *ht, t_ht_iter_f f)
{
	uint32_t	i;
	uint32_t	size;

	i = -1;
	size = ht->ht_size;
	while (++i < size)
		f(&ht->arr[i]);
}

void		ft_htiter_exist(t_hash_table *ht, t_ht_iter_f f)
{
	uint32_t	i;
	uint32_t	size;

	i = -1;
	size = ht->ht_size;
	while (++i < size)
		if (ht->arr[i].key)
			f(&ht->arr[i]);
}
