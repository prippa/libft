/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_table.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:30:33 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 14:41:03 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_TABLE_H
# define FT_HASH_TABLE_H

# include "ft_def.h"
# include "ft_cnt_general.h"

# define HT_MASK 777
# define HT_ELEM_SPACE 2.5

typedef struct s_ht_elem	t_ht_elem;
typedef struct s_hash_table	t_hash_table;

typedef void	(*t_ht_iter_f)(t_ht_elem *elem);

struct				s_ht_elem
{
	void			*key;
	void			*value;
	size_t			key_size;
	size_t			value_size;
};

struct				s_hash_table
{
	t_ht_elem		*arr;
	uint32_t		size;
	double			ht_size;
	t_delptr		del_key;
	t_delptr		del_value;
};

void				ft_htinit(t_hash_table *ht, double init_size,
						t_delptr del_key, t_delptr del_value);
uint32_t			ft_ht_hash(const void *key, size_t key_size,
						uint32_t ht_size);

void				ft_htinsert(t_hash_table *ht, const t_ht_elem *elem);
void				ft_htinsert_ref(t_hash_table *ht, const t_ht_elem *elem);
void				ft_ht_insert_logic(t_hash_table *ht,
						const t_ht_elem *elem, t_bool ref);
void				ft_htremove(t_hash_table *ht,
						const void *key, size_t key_size);
t_ht_elem			*ft_htget(t_hash_table *ht,
						const void *key, size_t key_size);

void				ft_ht_change_arr_size(t_hash_table *ht, t_bool incr);

void				ft_htiter_all(t_hash_table *ht, t_ht_iter_f f);
void				ft_htiter_exist(t_hash_table *ht, t_ht_iter_f f);

void				ft_htdel(t_hash_table *ht);
void				ft_htclear(t_hash_table *ht);

# define HT_INIT(h,is,dk,dv) ft_htinit(h, is, dk, dv)

# define HTE(k,v,ks,vs) {.key = k, .value = v, .key_size = ks, .value_size = vs}
# define HT_ELEM(k,v,ks,vs) &(t_ht_elem)HTE(k,v,ks,vs)
# define HT_INSERT(h,k,v,ks,vs) ft_htinsert(h, HT_ELEM(k,v,ks,vs))
# define HT_INSERT_REF(h,k,v,ks,vs) ft_htinsert_ref(h, HT_ELEM(k,v,ks,vs))

# define HT_GET(h,k,ks) ft_htget(h, k, ks)

# define HT_REMOVE(h,k,ks) ft_htremove(h, k, ks)

# define HT_DEL(h) ft_htdel(h)
# define HT_CLEAR(h) ft_htclear(h)

#endif
