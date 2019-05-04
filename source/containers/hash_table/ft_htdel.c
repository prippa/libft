/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htdel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:01:27 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:01:29 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_mem.h"

void	ft_htdel(t_hash_table *ht)
{
	uint32_t	i;
	uint32_t	size;

	i = -1;
	size = ht->ht_size;
	while (++i < size)
	{
		if (ht->del_key)
			ht->del_key(ht->arr[i].key, ht->arr[i].key_size);
		if (ht->del_value)
			ht->del_value(ht->arr[i].value, ht->arr[i].value_size);
	}
	ft_memdel((void **)&ht->arr);
}
