/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:41 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_mandelbrot(t_fractal *img)
{
	img->iter = 100;
	img->iter_increase = 25;
	img->iter_min = 100;
	img->iter_max = 500;
	img->color = 0x160C1D;
	img->color_max = 0x000000;
	img->view = (img->width + img->height) / 6;
	img->zoom = 1.50;
	img->scale = 1.50;
	img->x = -0.5;
	img->y = 0;
}

int	mandelbrot_set(t_fractal *img, double f_real, double f_imag)
{
	double	temp;
	double	real;
	double	imag;
	int		i;

	real = 0;
	imag = 0;
	i = 0;
	while (pow(real, 2) + pow(imag, 2) < 4 && i < img->iter)
	{
		temp = pow(real, 2) - pow(imag, 2) + f_real;
		imag = 2 * real * imag + f_imag;
		real = temp;
		i++;
	}
	return (i);
}
