/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 11:44:00 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:02:37 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

uint32_t	ft_ht_hash(const void *key, size_t key_size, uint32_t ht_size)
{
	const uint8_t	*ptr;
	uint32_t		hash;
	uint32_t		i;

	ptr = (const uint8_t *)key;
	hash = 0;
	i = -1;
	while (++i < key_size)
		hash = HT_MASK * hash + ptr[i];
	return (hash % ht_size);
}
