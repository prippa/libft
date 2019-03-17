/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 12:56:51 by prippa            #+#    #+#             */
/*   Updated: 2018/08/25 12:56:52 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_str.h"
#include "ft_def.h"
#include "ft_other.h"
#include <unistd.h>

int			ft_printf(const char *format, ...)
{
	t_printf fpf;

	fpf.format = format;
	fpf.fd = STDOUT_FILENO;
	fpf.buflen = 0;
	fpf.len = 0;
	va_start(fpf.args, format);
	fpf_lobi(&fpf);
	if (fpf.buflen)
		fpf.len += write(fpf.fd, fpf.buf, fpf.buflen);
	va_end(fpf.args);
	return (fpf.len);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	t_printf fpf;

	fpf.format = format;
	fpf.fd = fd;
	fpf.buflen = 0;
	fpf.len = 0;
	va_start(fpf.args, format);
	fpf_lobi(&fpf);
	if (fpf.buflen)
		fpf.len += write(fpf.fd, fpf.buf, fpf.buflen);
	va_end(fpf.args);
	return (fpf.len);
}

char		*ft_sprintf(const char *format, ...)
{
	t_printf	fpf;
	char		*s;

	fpf.format = format;
	fpf.fd = STDERR_FILENO;
	fpf.buflen = 0;
	fpf.len = 0;
	va_start(fpf.args, format);
	fpf_lobi(&fpf);
	if (fpf.buflen)
		s = ft_strsub(fpf.buf, 0, fpf.buflen);
	else
		s = ft_strdup(EMPTY_STR);
	if (!s)
		ft_perror_exit(MALLOC_ERR);
	va_end(fpf.args);
	return (s);
}
