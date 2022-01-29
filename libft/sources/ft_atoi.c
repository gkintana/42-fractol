/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 15:37:15 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 10:44:27 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	is_long(size_t c, int sign)
{
	if (c >= 9223372036854775808UL && sign == -1)
		return (0);
	else if ((c >= 9223372036854775807 && sign == 1))
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	size_t	num;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		num = (num * 10) + (str[i++] - 48);
	if (is_long(num, sign) == 0)
		return (0);
	else if (is_long(num, sign) == -1)
		return (-1);
	else
		return (sign * num);
}
