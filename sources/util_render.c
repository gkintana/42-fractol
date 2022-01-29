/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:51 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	fractal_init(t_fractal *img)
{
	if (img->fractal_type == 1)
		init_julia(img);
	else if (img->fractal_type == 2)
		init_mandelbrot(img);
	else if (img->fractal_type == 3)
		init_ship(img);
}

int	fractal_set(t_fractal *img, double real, double imag)
{
	int	frac;

	frac = julia_set(img, real, -imag);
	if (img->fractal_type == 2)
		frac = mandelbrot_set(img, real, imag);
	else if (img->fractal_type == 3)
		frac = ship_set(img, real, imag);
	return (frac);
}

void	program_guide(t_fractal *img)
{
	mlx_string_put(img->mlx, img->win, 10, 20, X_GREEN, PG_TITLE);
	mlx_string_put(img->mlx, img->win, 20, 40, X_GREEN, PG_EXIT);
	mlx_string_put(img->mlx, img->win, 20, 55, X_GREEN, PG_ZOOM);
	mlx_string_put(img->mlx, img->win, 20, 70, X_GREEN, PG_MOVE);
	mlx_string_put(img->mlx, img->win, 20, 85, X_GREEN, PG_COLOR);
	mlx_string_put(img->mlx, img->win, 20, 100, X_GREEN, PG_RESET);
	mlx_string_put(img->mlx, img->win, 20, 115, X_GREEN, PG_JUL);
	mlx_string_put(img->mlx, img->win, 20, 130, X_GREEN, PG_MAN);
	mlx_string_put(img->mlx, img->win, 20, 145, X_GREEN, PG_BS);
	mlx_string_put(img->mlx, img->win, 20, 160, X_GREEN, PG_GUIDE);
	mlx_string_put(img->mlx, img->win, 20, 175, X_GREEN, PG_DI);
	mlx_string_put(img->mlx, img->win, 20, 190, X_GREEN, PG_II);
}
