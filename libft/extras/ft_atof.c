/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:33:45 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/07 01:17:21 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	check_space(const char *str)
{
	int	spaces;

	spaces = 0;
	while (ft_isspace(str[spaces]))
		spaces++;
	return (spaces);
}

static int	check_precision(const char *str)
{
	if (*str == '.')
		return (1);
	else
		return (0);
}

double	ft_atof(const char *str)
{
	int			i;
	int			sign;
	int			power;
	double		num;

	i = check_space(str);
	sign = 1;
	if (str[i] == '-' && ft_isdigit(str[++i]))
		sign = -1;
	num = 0;
	while (ft_isdigit(str[i]))
		num = num * 10 + (str[i++] - 48);
	i += check_precision(&str[i]);
	power = 1;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - 48);
		power *= 10;
	}
	return (sign * (num / power));
}
