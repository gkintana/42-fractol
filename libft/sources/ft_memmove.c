/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 15:53:20 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 10:48:10 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*eo_dst;
	unsigned char	*srce;
	unsigned char	*eo_src;

	if (!dst && !src)
		return (NULL);
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	if (srce > dest)
		ft_memcpy(dest, srce, len);
	else
	{
		eo_dst = dest + len - 1;
		eo_src = srce + len - 1;
		while (len-- > 0)
			*eo_dst-- = *eo_src--;
	}
	return (dst);
}
