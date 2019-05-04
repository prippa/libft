/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:36:41 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:36:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

t_list_elem	*ft_lstnew(void const *content, size_t content_size)
{
	t_list_elem	*new_obj;
	void		*data;

	data = NULL;
	if (content)
	{
		data = ft_memalloc(content_size);
		ft_memcpy(data, content, content_size);
	}
	else
		content_size = 0;
	new_obj = (t_list_elem *)ft_memalloc(sizeof(t_list_elem));
	new_obj->content = data;
	new_obj->content_size = content_size;
	return (new_obj);
}

t_list_elem	*ft_lstnew_ref(void *content, size_t content_size)
{
	t_list_elem	*new_obj;

	if (!content)
		content_size = 0;
	new_obj = (t_list_elem *)ft_memalloc(sizeof(t_list_elem));
	new_obj->content = content;
	new_obj->content_size = content_size;
	return (new_obj);
}
