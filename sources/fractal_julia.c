/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:39 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_julia(t_fractal *img)
{
	if (!img->has_args)
	{
		img->real_arg = 0.285;
		img->imag_arg = 0.01;
	}
	img->iter = 100;
	img->iter_increase = 100;
	img->iter_min = 100;
	img->iter_max = 1500;
	img->color = 0x012345;
	img->color_max = 0x880000;
	img->view = (img->width + img->height) / 6;
	img->zoom = 1.50;
	img->scale = 1.50;
	img->x = 0;
	img->y = 0;
}

int	julia_set(t_fractal *img, double real, double imag)
{
	double	temp;
	int		i;

	i = 0;
	while (pow(real, 2) + pow(imag, 2) < 4 && i < img->iter)
	{
		temp = pow(real, 2) - pow(imag, 2);
		imag = 2 * real * imag + img->imag_arg;
		real = temp + img->real_arg;
		i++;
	}
	return (i);
}
