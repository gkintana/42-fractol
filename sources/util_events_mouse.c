/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_events_mouse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:50 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	zoom_in(int x, int y, t_fractal *img)
{
	double	bz_x;
	double	az_x;
	double	bz_y;
	double	az_y;

	bz_x = ((x - (img->width >> 1)) / img->view + img->x);
	az_x = ((x - (img->width >> 1)) / (img->view * img->zoom) + img->x);
	bz_y = ((y - (img->height >> 1)) / img->view + img->y);
	az_y = ((y - (img->height >> 1)) / (img->view * img->zoom) + img->y);
	img->view *= img->scale;
	img->x += bz_x - az_x;
	img->y += bz_y - az_y;
}

void	zoom_out(int x, int y, t_fractal *img)
{
	double	bz_x;
	double	az_x;
	double	bz_y;
	double	az_y;

	bz_x = ((x - (img->width >> 1)) / img->view + img->x);
	az_x = ((x - (img->width >> 1)) / (img->view * img->zoom) + img->x);
	bz_y = ((y - (img->height >> 1)) / img->view + img->y);
	az_y = ((y - (img->height >> 1)) / (img->view * img->zoom) + img->y);
	img->view /= img->scale;
	img->x -= bz_x - az_x;
	img->y -= bz_y - az_y;
}
