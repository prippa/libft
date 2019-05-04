/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:37:47 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 14:37:47 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash_table.h"

void	ft_htclear(t_hash_table *ht)
{
	ft_htdel(ht);
	ft_htinit(ht, 0, ht->del_key, ht->del_value);
}
