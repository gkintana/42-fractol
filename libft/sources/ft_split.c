/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:21:50 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 10:49:23 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	**ft_undo_alloc(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static int	ft_strcount(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_cpystr(char const *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, i);
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nbr_of_str;
	int		i;

	if (!s)
		return (NULL);
	nbr_of_str = ft_strcount(s, c);
	split = (char **)malloc(sizeof(char *) * (nbr_of_str + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < nbr_of_str)
	{
		while (*s == c)
			s++;
		split[i] = ft_cpystr(s, c);
		if (!split[i])
			return (ft_undo_alloc(split));
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}
