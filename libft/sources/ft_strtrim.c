/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:06:58 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 10:50:35 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_isset(int c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		beg;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	while (s1[beg] != '\0' && ft_isset(s1[beg], (char *)set))
		beg++;
	end = ft_strlen(s1);
	while (end > beg && ft_isset(s1[end - 1], (char *)set))
		end--;
	trim = (char *)malloc(sizeof(char) * (end + 1 - beg));
	if (trim == NULL)
		return (NULL);
	i = 0;
	while (beg < end)
		trim[i++] = s1[beg++];
	trim[i] = '\0';
	return (trim);
}
