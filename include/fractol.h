/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 12:47:05 by gkintana          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:32 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*------------------------------- COLOR CODES -------------------------------*/
# define DEFAULT		"\033[0m"
# define RED			"\033[1;31m"
# define GREEN			"\033[0;32m"
# define YELLOW			"\033[0;33m"
# define YELLOW_I		"\033[3;33m"
# define X_GREEN		0x00FF00

/*------------------------------ FRACT'OL ARGS ------------------------------*/
# define ARGS			"ERROR!\nExpected: ./fractol [Fractal Set]\n"
# define SET_MSG		"Supported Fractal Sets:\n"
# define SET_TYPE		"   ➢  Julia\n   ➢  Mandelbrot\n   ➢  Ship\n"
# define NOTE1			"Julia Set can accept two additional parameters "
# define NOTE2			"that represent the real and imaginary component of "
# define NOTE3			"a complex number respectively.\n\n"
# define LIST			"Listed below are some examples:\n"
# define EX01			"   ./fractol Julia -0.4 0.6;\n"
# define EX02			"   ./fractol Julia 0.285 0;\n"
# define EX03			"   ./fractol Julia 0.45 0.1428;\n"
# define EX04			"   ./fractol Julia -0.70176 -0.3842;\n"
# define EX05			"   ./fractol Julia -0.835 -0.2321;\n"
# define EX06			"   ./fractol Julia -0.7269 0.1889;\n"
# define EX07			"   ./fractol Julia -0.8 0.156;\n"
# define EX08			"   ./fractol Julia -0.8 0;\n"
# define EX09			"   ./fractol Julia 0 -0.8;\n"
# define EX10			"   ./fractol Julia -0.162 1.04;\n"
# define EX11			"   ./fractol Julia -1.476 0;\n"
# define EX12			"   ./fractol Julia -0.74543 0.11301;\n"
# define EX13			"   ./fractol Julia -0.75 0.11;\n"
# define EX14			"   ./fractol Julia -0.1 0.651;\n"
# define JUL			"julia"
# define MAN			"mandelbrot"
# define SHIP			"ship"
# define GEN_JUL_FRAC4	"Generating Julia Fractal: %.4f + %.4fi\n"
# define GEN_JUL_FRAC2	"Generating Julia Fractal: 0.2850 + 0.0100i\n"
# define GEN_MAN_FRAC	"Generating Mandelbrot Fractal\n"
# define GEN_SHIP_FRAC	"Generating Burning Ship Fractal\n"

/*------------------------------ PROGRAM GUIDE ------------------------------*/
# define PG_TITLE		"Program Guide"
# define PG_EXIT		"ESC = Exit Program"
# define PG_ZOOM		"Scroll Wheel = Zoom In/Out"
# define PG_MOVE		"Arrow Keys = Move Fractal"
# define PG_COLOR		"Numbers 1 to 9 = Change Colors"
# define PG_RESET		"R = Reset Fractal"
# define PG_JUL			"J = Julia Fractal"
# define PG_MAN			"M = Mandelbrot Fractal"
# define PG_BS			"B = Burning Ship Fractal"
# define PG_GUIDE		"G = Show/Hide Program Guide"
# define PG_DI			"[ = Decrease Fractal Iteration"
# define PG_II			"] = Increase Fractal Iteration"

/*-------------------------------- LIBRARIES --------------------------------*/
# include <libft.h>
# include <key_binding.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

/*---------------------------- PROGRAM STRUCTURE ----------------------------*/
typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	*title;
	int		guide_on;

	int		fractal_type;	
	void	*render;
	char	*addr;
	int		bpp;
	int		len;
	int		end;

	int		mlx_start;
	int		has_args;
	double	real_arg;
	double	imag_arg;

	int		iter;
	int		iter_increase;
	int		iter_min;
	int		iter_max;

	int		color;
	int		color_max;

	double	view;
	double	zoom;
	double	scale;
	double	x;
	double	y;
}				t_fractal;

/*--------------------------- FUNCTION PROTOTYPES ---------------------------*/
void		check_conditions(int argc, char *argv, char *real, char *imag);
int			check_argv(char *argv);

void		init_julia(t_fractal *img);
void		init_mandelbrot(t_fractal *img);
void		init_ship(t_fractal *img);
int			julia_set(t_fractal *img, double f_real, double f_imag);
int			mandelbrot_set(t_fractal *img, double f_real, double f_imag);
int			ship_set(t_fractal *img, double f_real, double f_imag);

void		fractal_init(t_fractal *img);
int			fractal_set(t_fractal *img, double real, double imag);
void		program_guide(t_fractal *img);
void		render_fractal(t_fractal *img, int x, int y);

void		zoom_in(int x, int y, t_fractal *img);
void		zoom_out(int x, int y, t_fractal *img);
int			mouse(int mouse_input, int x, int y, t_fractal *img);
void		change_color(int key_input, t_fractal *img);
void		arrows_x(int key_input, t_fractal *img, int distance);
void		arrows_y(int key_input, t_fractal *img, int distance);
int			keyboard(int key_input, t_fractal *img);
int			close_window(void);

void		change_fractal(int key_input, t_fractal *img);
void		extras(int key_input, t_fractal *img);

#endif
