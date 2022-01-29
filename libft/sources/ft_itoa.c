/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 14:34:25 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 10:45:42 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	absolute(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static int	nbrlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = nbrlen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0)
		str[0] = '-';
	else if (n == 0)
		str[i] = '0';
	while (n != 0)
	{
		str[i] = absolute(n % 10) + 48;
		n /= 10;
		i--;
	}
	return (str);
}
