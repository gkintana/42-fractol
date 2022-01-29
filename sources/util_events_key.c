/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_events_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:48 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	arrows_x(int key_input, t_fractal *img, int distance)
{
	double	bz_x;
	double	az_x;

	bz_x = ((distance - (img->width >> 1)) / img->view + img->x);
	az_x = ((distance - (img->width >> 1)) / (img->view * img->zoom) + img->x);
	if (key_input == ARROW_LEFT)
	{
		printf("Left Arrow Key Pressed\n");
		img->x += bz_x - az_x;
	}
	else if (key_input == ARROW_RIGHT)
	{
		printf("Right Arrow Key Pressed\n");
		img->x -= bz_x - az_x;
	}
}

void	arrows_y(int key_input, t_fractal *img, int distance)
{
	double	bz_y;
	double	az_y;

	bz_y = ((distance - (img->height >> 1)) / img->view + img->y);
	az_y = ((distance - (img->height >> 1)) / (img->view * img->zoom) + img->y);
	if (key_input == ARROW_UP)
	{
		printf("Up Arrow Key Pressed\n");
		img->y += bz_y - az_y;
	}
	else if (key_input == ARROW_DOWN)
	{
		printf("Down Arrow Key Pressed\n");
		img->y -= bz_y - az_y;
	}
}

void	change_color(int key_input, t_fractal *img)
{
	int	current;

	current = img->color;
	if (key_input == NUM_1)
		img->color = 0x123456;
	else if (key_input == NUM_2)
		img->color = 0x234567;
	else if (key_input == NUM_3)
		img->color = 0x345678;
	else if (key_input == NUM_4)
		img->color = 0x456789;
	else if (key_input == NUM_5)
		img->color = 0x56789A;
	else if (key_input == NUM_6)
		img->color = 0xABCDEF;
	else if (key_input == NUM_7)
		img->color = 0xBCDEF0;
	else if (key_input == NUM_8)
		img->color = 0xCDEF01;
	else if (key_input == NUM_9)
		img->color = 0xDEF012;
	if (current != img->color)
		printf("Changed Color\n");
}

void	change_fractal(int key_input, t_fractal *img)
{
	if ((key_input == J && img->fractal_type == 1)
		|| (key_input == M && img->fractal_type == 2)
		|| (key_input == B && img->fractal_type == 3))
		printf("Selected fractal is already being displayed\n");
	else if (key_input == J && img->fractal_type != 1)
	{
		img->fractal_type = 1;
		init_julia(img);
		printf("Switching to Julia Fractal\n");
	}
	else if (key_input == M && img->fractal_type != 2)
	{
		img->fractal_type = 2;
		init_mandelbrot(img);
		printf("Switching to Mandelbrot Fractal\n");
	}
	else if (key_input == B && img->fractal_type != 3)
	{
		img->fractal_type = 3;
		init_ship(img);
		printf("Switching to Burning Ship Fractal\n");
	}
}

void	extras(int key_input, t_fractal *img)
{
	if (key_input == G && img->guide_on)
	{
		img->guide_on = 0;
		printf("Program Guide Off\n");
	}
	else if (key_input == G && !img->guide_on)
	{
		img->guide_on = 1;
		printf("Program Guide On\n");
	}
	else if (key_input == L_BRACKET && img->iter <= img->iter_min)
		printf("Minimum Iteration Reached\n");
	else if (key_input == L_BRACKET && img->iter > img->iter_min)
	{
		img->iter -= img->iter_increase;
		printf("Current Iteration: %d\n", img->iter);
	}
	else if (key_input == R_BRACKET && img->iter >= img->iter_max)
		printf("Maximum Iteration Reached\n");
	else if (key_input == R_BRACKET && img->iter < img->iter_max)
	{
		img->iter += img->iter_increase;
		printf("Current Iteration: %d\n", img->iter);
	}
}
