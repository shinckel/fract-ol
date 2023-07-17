/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:55 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/17 22:30:43 by shinckel         ###   ########.fr       */
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
// # define PLUS 65451
// # define MINUS 65453

// for my MAC(only use it at home)
# define SPACE 32
# define TAB 65289
// errors
# define MINILIBX "\e[1;41m failed to initialize MiniLibX \e[0m \n"
# define PARAM "\e[1;41m write 1 fractol name: mandelbrot/ julia/ phoenix \e[0m \n"

typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_complex_c
{
    double x;
    double y;
} t_complex_c;

typedef struct s_fractal {

	void		*mlx;
	void		*win;

	t_list		*list;
	t_list		*head;
	t_list		*list_color;
	t_list		*head_color;

	t_list		*copy;
	t_list		*copy_head;

	int			flag;

	int			pixel_color;

	double		cx;
	double		cy;
	double		zx_new;
	double		zy_new;
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
}	t_fractal;

/* draw fractals */
void draw_frac(t_fractal *frac, int flag);
double	mandelbrot(int x, int y);
double	julia(int x, int y, t_complex_c *c);
/* julia parameters */
void	julia_list(t_fractal *frac, t_list **head);
/* control hooks */
void	change_sets(t_fractal *frac, t_list **list, t_list *head);
int		key_hook(int keycode, t_fractal *frac);
/* colors */
double	smooth_coloring(t_complex_c *c, double x, double y);
void	get_color(double mu, t_fractal *frac, t_list **head);

#endif