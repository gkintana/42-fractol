/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:44 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_fractal(t_fractal *img, int argv, char *real, char *imag)
{
	img->mlx = mlx_init();
	img->width = 1000;
	img->height = 800;
	img->title = "Fractal Exploration Program";
	img->win = mlx_new_window(img->mlx, img->width, img->height, img->title);
	img->render = mlx_new_image(img->mlx, img->width, img->height);
	img->addr = mlx_get_data_addr(img->render, &img->bpp, &img->len, &img->end);
	img->mlx_start = 1;
	img->guide_on = 1;
	img->has_args = 0;
	if (real && imag)
	{
		img->has_args = 1;
		img->real_arg = ft_atof(real);
		img->imag_arg = ft_atof(imag);
	}
	if (argv == 1)
		img->fractal_type = 1;
	else if (argv == 2)
		img->fractal_type = 2;
	else if (argv == 3)
		img->fractal_type = 3;
	render_fractal(img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_fractal	img;

	check_conditions(argc, argv[1], argv[2], argv[3]);
	init_fractal(&img, check_argv(argv[1]), argv[2], argv[3]);
	mlx_key_hook(img.win, keyboard, &img);
	mlx_mouse_hook(img.win, mouse, &img);
	mlx_hook(img.win, 17, 1L << 17, close_window, NULL);
	mlx_loop(img.mlx);
	exit(EXIT_SUCCESS);
}
