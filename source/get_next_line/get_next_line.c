/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:47:04 by prippa            #+#    #+#             */
/*   Updated: 2017/11/22 17:47:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_def.h"
#include "ft_str.h"
#include "ft_mem.h"
#include <unistd.h>

static int32_t	gnl_sub_line(t_gnl *file, char **line)
{
	uint32_t start;

	if (!file->s[file->i])
	{
		ft_strdel(&file->s);
		return (0);
	}
	start = (uint32_t)file->i;
	while (file->s[file->i] && file->s[file->i] != ENDL)
		++file->i;
	*line = ft_strsub(file->s, start, file->i - start);
	if (file->s[file->i])
		++file->i;
	return (1);
}

static int32_t	gnl_remainder(t_gnl *file)
{
	if (!file->s)
	{
		file->s = ft_strdup(EMPTY_STR);
		return (1);
	}
	ft_strdup_free(&file->s, &file->s[file->i]);
	file->i = 0;
	return (1);
}

static int32_t	gnl_read_file(t_gnl *file, char **line)
{
	intmax_t	ret;
	char		buf[BUFF_SIZE + 1];

	while ((ret = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		ft_strjoin_free(&file->s, buf, ft_strlen(file->s), ret);
		if (ft_strchr(buf, ENDL))
			break ;
	}
	if (ret == ERR)
		return (ERR);
	return (gnl_sub_line(file, line));
}

static t_gnl	*gnl_add_or_get_file(t_gnl **g, int32_t fd)
{
	t_gnl *file;

	file = *g;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	file = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	file->fd = fd;
	file->next = *g;
	*g = file;
	return (file);
}

int32_t			get_next_line(int32_t const fd, char **line)
{
	static t_gnl	*g;
	t_gnl			*current;

	if (fd < 0 || !line || read(fd, NULL, 0) == ERR)
		return (ERR);
	if (!(current = gnl_add_or_get_file(&g, fd)))
		return (ERR);
	if (current->s && ft_strchr(&current->s[current->i], ENDL))
		return (gnl_sub_line(current, line));
	if ((gnl_remainder(current)) == ERR)
		return (ERR);
	return (gnl_read_file(current, line));
}
