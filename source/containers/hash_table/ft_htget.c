/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htget.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:00:37 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:00:45 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_mem.h"

t_ht_elem	*ft_htget(t_hash_table *ht, const void *key, size_t key_size)
{
	uint32_t	hash;
	uint32_t	ht_size;
	uint32_t	i;

	ht_size = ht->ht_size;
	hash = ft_ht_hash(key, key_size, ht_size);
	i = -1;
	while (++i < ht_size)
	{
		if (ht->arr[hash].key &&
			ht->arr[hash].key_size == key_size &&
			!ft_memcmp(ht->arr[hash].key, key, key_size))
			return (&ht->arr[hash]);
		hash = ((hash + 1) % ht_size);
	}
	return (NULL);
}
