/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ht_insert_logic.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 18:00:29 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 18:02:19 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"
#include "ft_mem.h"

static void	ft_ht_new_value(t_ht_elem *dst, const t_ht_elem *src, t_bool ref)
{
	if (!ref)
	{
		if (src->value)
		{
			dst->value = ft_memalloc(src->value_size);
			ft_memcpy(dst->value, src->value, src->value_size);
			dst->value_size = src->value_size;
		}
		else
		{
			dst->value = NULL;
			dst->value_size = 0;
		}
	}
	else
	{
		dst->value = src->value;
		if (src->value)
			dst->value_size = src->value_size;
		else
			dst->value_size = 0;
	}
}

static void	ft_ht_insert_move(t_ht_elem *dst,
				const t_ht_elem *src, t_bool ref)
{
	if (!ref)
	{
		dst->key = ft_memalloc(src->key_size);
		ft_memcpy(dst->key, src->key, src->key_size);
		dst->key_size = src->key_size;
		ft_ht_new_value(dst, src, ref);
	}
	else
	{
		dst->key = src->key;
		dst->key_size = src->key_size;
		ft_ht_new_value(dst, src, ref);
	}
}

static void	ft_ht_make_insert_or_replace_op(t_hash_table *ht,
				const t_ht_elem *elem, t_bool ref, uint32_t hash)
{
	while (true)
	{
		if (!ht->arr[hash].key)
		{
			ft_ht_insert_move(&ht->arr[hash], elem, ref);
			++ht->size;
			break ;
		}
		if (ht->arr[hash].key_size == elem->key_size &&
			!ft_memcmp(ht->arr[hash].key, elem->key, elem->key_size))
		{
			if (ht->del_value)
				ht->del_value(ht->arr[hash].value, ht->arr[hash].value_size);
			ft_ht_new_value(&ht->arr[hash], elem, ref);
			break ;
		}
		hash = ((hash + 1) % (uint32_t)ht->ht_size);
	}
}

void		ft_ht_insert_logic(t_hash_table *ht,
				const t_ht_elem *elem, t_bool ref)
{
	if (!elem || !elem->key)
		return ;
	ft_ht_make_insert_or_replace_op(ht, elem, ref,
		ft_ht_hash(elem->key, elem->key_size, ht->ht_size));
	if (ht->size * HT_ELEM_SPACE > ht->ht_size)
		ft_ht_change_arr_size(ht, true);
}
