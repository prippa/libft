/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sys.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <prippa@student.unit.ua>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 22:34:47 by prippa            #+#    #+#             */
/*   Updated: 2019/04/29 22:45:38 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SYS_H
# define FT_SYS_H

# include <dirent.h>

# define OPENDIR_FAILED		"opendir() failed"
# define CLOSEDIR_FAILED	"closedir() failed"

typedef void	(*t_sys_readdir)(const char *path, struct dirent *dit);

void		ft_sys_readdir(const char *path, t_sys_readdir f);

#endif
