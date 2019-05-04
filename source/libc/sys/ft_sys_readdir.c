/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys_readdir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:39:38 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 22:45:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sys.h"
#include "ft_def.h"

void	ft_sys_readdir(const char *path, t_sys_readdir f)
{
	DIR				*dip;
	struct dirent	*dit;

	if (!(dip = opendir(path)))
		g_fef(OPENDIR_FAILED);
	while ((dit = readdir(dip)))
		f(path, dit);
	if ((closedir(dip)) == ERR)
		g_fef(CLOSEDIR_FAILED);
}
