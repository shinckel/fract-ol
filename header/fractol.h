/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:55 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/03 18:03:49 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/header/libft.h"

// window
# define WIDTH 720
# define HEIGHT 720
// iterations
# define MAX_ITER 1500
// hooks
# define ESC_KEY 65307
# define LEFT_ARROW 65361 
# define RIGHT_ARROW 65363
# define DOWN 65364 
# define PLUS 65451
# define MINUS 65453
// errors
# define MINILIBX "\e[1;41m failed to initialize MiniLibX \e[0m \n"
# define PARAM "\e[1;41m write 1 fractol name: mandelbrot/ julia/ phoenix \e[0m \n"

typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_fractal {

	void		*mlx;
	void		*win;

	double		cx;
	double		cy;
	double		zx_new;
	double		zy_new;
	double		zoom;
	char		*name;

	int			flag;

	double		x2;
	double		y2;
	double		tmp;

	double		xarrow;
	double		yarrow;
	double		radius;

	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_fractal;

/* draw fractals */
void	draw_frac(t_fractal *frac, char *name);
t_color	mandelbrot(t_fractal *frac, int x, int y);
t_color	julia(t_fractal *frac, int x, int y);
/* control hooks */
int		key_hook(int keycode, t_fractal *frac);
/* colors */
double	smooth_coloring(t_fractal *frac, double x, double y);
t_color	get_color(double smoothCount, int flag);

#endif