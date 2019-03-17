/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_lobi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:47:32 by prippa            #+#    #+#             */
/*   Updated: 2019/03/12 12:47:35 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mem.h"
#include <unistd.h>

static void	fpf_dispatcher(t_printf *fpf)
{
	fpf_before_processing_data(fpf);
	if (fpf->type == 's' || fpf->type == 'S')
		fpf_output_s(fpf);
	else if (fpf->type == 'd' || fpf->type == 'i' || fpf->type == 'D')
		fpf_output_d(fpf);
	else if (fpf->type == 'c' || fpf->type == 'C')
		fpf_output_c(fpf);
	else if (fpf->type == 'u' || fpf->type == 'U')
		fpf_output_u(fpf);
	else if (fpf->type == 'o' || fpf->type == 'O'
		|| fpf->type == 'x' || fpf->type == 'X')
		fpf_output_ox(fpf);
	else
		fpf_output_p(fpf);
	fpf_after_processing_data(fpf);
}

static void	fpf_handle_type(t_printf *fpf)
{
	fpf->size_flag = 0;
	fpf->width = 0;
	fpf->precision = 0;
	fpf->color = 0;
	fpf->color_type = 0;
	fpf->type = 0;
	fpf->str = NULL;
	ft_bzero(fpf->f, FLAG_SIZE);
	fpf_parser(fpf);
	if (fpf->str)
	{
		fpf_dispatcher(fpf);
		free(fpf->str);
	}
}

void		fpf_lobi(t_printf *fpf)
{
	while (*fpf->format)
	{
		if (*fpf->format == '%')
			fpf_handle_type(fpf);
		else
			fpf_cat_char(fpf, *fpf->format++);
	}
}
