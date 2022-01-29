/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:36 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int	free_av(char *av, int num)
{
	free(av);
	return (num);
}

static int	cmplen(char *s1, char *s2)
{
	if (ft_strlen(s1) == ft_strlen(s2))
		return (0);
	else
		return (ft_strlen(s1) - ft_strlen(s2));
}

int	check_argv(char *argv)
{
	char	*av;
	int		i;

	av = (char *)ft_calloc(ft_strlen(argv) + 1, sizeof(char));
	if (!av)
		return (0);
	i = -1;
	while (++i < (int)ft_strlen(argv))
		av[i] = ft_tolower(argv[i]);
	if (!ft_strncmp(av, JUL, ft_strlen(JUL)) && !cmplen(av, JUL))
		return (free_av(av, 1));
	else if (!ft_strncmp(av, MAN, ft_strlen(MAN)) && !cmplen(av, MAN))
		return (free_av(av, 2));
	else if (!ft_strncmp(av, SHIP, ft_strlen(SHIP)) && !cmplen(av, SHIP))
		return (free_av(av, 3));
	else
		return (free_av(av, 0));
}

void	check_conditions(int argc, char *argv, char *real, char *imag)
{
	int		complex_ok;

	complex_ok = 0;
	if (argc == 4 && check_argv(argv) == 1
		&& ft_strlen(real) <= 10 && ft_strlen(imag) <= 10
		&& ft_atof(real) >= -2.0 && ft_atof(real) <= 2.0
		&& ft_atof(imag) >= -2.0 && ft_atof(imag) <= 2.0)
		complex_ok = 1;
	if (argc == 4 && check_argv(argv) == 1 && complex_ok)
		printf(GREEN GEN_JUL_FRAC4, ft_atof(real), ft_atof(imag));
	else if (argc == 2 && check_argv(argv) == 1)
		printf(GREEN GEN_JUL_FRAC2);
	else if (argc == 2 && check_argv(argv) == 2)
		printf(GREEN GEN_MAN_FRAC);
	else if (argc == 2 && check_argv(argv) == 3)
		printf(GREEN GEN_SHIP_FRAC);
	else
	{
		printf(RED ARGS YELLOW SET_MSG SET_TYPE YELLOW_I NOTE1 NOTE2 NOTE3);
		printf(YELLOW LIST EX01 EX02 EX03 EX04 EX05 EX06 EX07 EX08 EX09);
		printf(EX10 EX11 EX12 EX13 EX14 DEFAULT);
		exit(EXIT_FAILURE);
	}
}
