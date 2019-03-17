/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:58:54 by prippa            #+#    #+#             */
/*   Updated: 2018/03/12 21:52:51 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_def.h"

static const char	*g_ct[CT_SIZE] =
{
	BOLD, DIM, ITALIC, UNDER_LINE, BACK
};

static const char	*g_c[C_SIZE] =
{
	RED, YELLOW, GREEN, CYAN, BLUE, MAGENTA, GRAY, WHITE
};

void		fpf_set_color(t_printf *fpf)
{
	if (fpf->color_type >= 0 && fpf->color_type < CT_SIZE)
		fpf_cat_str(fpf, g_ct[fpf->color_type]);
	if (fpf->color >= 0 && fpf->color < C_SIZE)
		fpf_cat_str(fpf, g_c[fpf->color]);
}
