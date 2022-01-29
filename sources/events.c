/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:38 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	mouse(int mouse_input, int x, int y, t_fractal *img)
{
	if (mouse_input == SCROLL_WHEEL_UP)
	{
		zoom_in(x, y, img);
		printf("Zoomed In\n");
	}
	else if (mouse_input == SCROLL_WHEEL_DOWN)
	{
		zoom_out(x, y, img);
		printf("Zoomed Out\n");
	}
	mlx_clear_window(img->mlx, img->win);
	render_fractal(img, 0, 0);
	return (0);
}

int	keyboard(int key_input, t_fractal *img)
{
	if (key_input == ESC)
	{
		printf("Program Terminated\n");
		exit(EXIT_SUCCESS);
	}
	else if (key_input == R)
	{
		img->mlx_start = 1;
		printf("Fractal Reset\n");
	}
	change_fractal(key_input, img);
	change_color(key_input, img);
	arrows_x(key_input, img, 100);
	arrows_y(key_input, img, 100);
	extras(key_input, img);
	mlx_clear_window(img->mlx, img->win);
	render_fractal(img, 0, 0);
	return (0);
}

int	close_window(void)
{
	printf("Program Terminated\n");
	exit(EXIT_SUCCESS);
}
