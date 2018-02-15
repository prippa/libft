#include "ft_printf.h"

void	ft_fpf_color(t_printf *fpf)
{
	if (fpf->color == F_RED)
		ft_pf_strjoin(fpf, RED, ft_strlen(RED));
	else if (fpf->color == F_YELLOW)
		ft_pf_strjoin(fpf, YELLOW, ft_strlen(YELLOW));
	else if (fpf->color == F_GREEN)
		ft_pf_strjoin(fpf, GREEN, ft_strlen(GREEN));
	else if (fpf->color == F_CYAN)
		ft_pf_strjoin(fpf, CYAN, ft_strlen(CYAN));
	else if (fpf->color == F_BLUE)
		ft_pf_strjoin(fpf, BLUE, ft_strlen(BLUE));
	else if (fpf->color == F_MAGENTA)
		ft_pf_strjoin(fpf, MAGENTA, ft_strlen(MAGENTA));
	else if (fpf->color == F_WHITE)
		ft_pf_strjoin(fpf, WHITE, ft_strlen(WHITE));
}
