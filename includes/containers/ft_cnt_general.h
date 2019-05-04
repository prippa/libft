/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_general.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 17:58:01 by prippa            #+#    #+#             */
/*   Updated: 2019/04/19 17:58:02 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CNT_GENERAL_H
# define FT_CNT_GENERAL_H

# include <stddef.h>

typedef void	(*t_delptr)(void *ptr, size_t ptr_size);

void	ft_cnt_delptr(void *ptr, size_t ptr_size);

#endif
