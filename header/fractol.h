/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:55 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/03 11:50:42 by shinckel         ###   ########.fr       */
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
# define ESC_KEY 81
# define RIGHT_ARROW 39
# define LEFT_ARROW 37
// errors
# define MINILIBX "\e[1;41m ERROR failed to initialize MiniLibX \e[0m \n"
# define PARAM "\e[1;41m ERROR write one fractol name: mandelbrot - julia - \e[0m \n"

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} color;

typedef struct {

	void		*mlx;
	void		*win;

	double		cx;
	double		cy;
	double		zx_new;
	double		zy_new;
	double		outer;
	double		zoom;
	char		*name;



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
}	fractal;

/* draw fractals */
color	mandelbrot(fractal *frac, int x, int y);
color	julia(fractal *frac, int x, int y);
/* control hooks */

/* colors */
double	smoothColoring(fractal *frac, double x, double y);
color	getColor(double smoothCount);

#endif