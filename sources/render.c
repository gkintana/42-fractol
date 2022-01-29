/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:47 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static double	map(t_fractal *img, int x, int y)
{
	double	map;

	map = 0;
	if (x && !y)
		map = (x - (img->width >> 1)) / img->view + img->x;
	else if (!x && y)
		map = (y - (img->height >> 1)) / img->view + img->y;
	return (map);
}

static void	put_pixel_at_addr(t_fractal *img, int x, int y, unsigned int color)
{
	char			*pixel;
	unsigned int	pixel_position;

	pixel = NULL;
	pixel_position = 0;
	if (x < img->width && y < img->height)
	{
		pixel_position = (y * img->len) + (x * (img->bpp >> 3));
		pixel = img->addr + pixel_position;
		*(unsigned int *)pixel = color;
	}
}

void	render_fractal(t_fractal *img, int x, int y)
{
	double	real;
	double	imag;
	int		fractal;

	if (img->mlx_start)
		fractal_init(img);
	while (y++ < img->height)
	{
		x = 0;
		while (x++ < img->width)
		{
			real = map(img, x, 0);
			imag = map(img, 0, y);
			fractal = fractal_set(img, real, imag);
			if (fractal == img->iter)
				put_pixel_at_addr(img, x, y, img->color_max);
			else
				put_pixel_at_addr(img, x, y, img->color * fractal);
		}
	}
	img->mlx_start = 0;
	mlx_put_image_to_window(img->mlx, img->win, img->render, 0, 0);
	if (img->guide_on)
		program_guide(img);
}
