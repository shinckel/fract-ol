/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:55 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/07 11:35:52 by shinckel         ###   ########.fr       */
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
// # define MAX_ITER 1500
// hooks
# define ESC_KEY 65307
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define MINUS 45
# define SPACE 32
# define TAB 65289
# define H 104
# define R 114
# define Z 122
# define M 109
# define J 106
# define P 112
// errors and messages
# define MINILIBX "\e[1;30;41m Failed to initialize MiniLibX \e[0m \n"
# define PARAM "\e[1;30;41m Write 1 name: mandelbrot/ julia/ phoenix \e[0m \n"
# define RESET "\e[1;30;103m Reset view \e[0m \n"
# define FINISH "\e[1;30;41m Finish game \e[0m \n"

typedef struct s_color {
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct s_complex {
	double	x;
	double	y;
}	t_complex;

typedef struct s_fractal {
	void		*mlx;
	void		*win;
	t_list		*list;
	t_list		*head;
	t_list		*list_color;
	t_list		*head_color;
	int			flag;
	int			pixel_color;
	int			help;
	double		zx;
	double		zy;
	double		mu;
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
	int			iterations;
}	t_fractal;

/* draw fractals */
void	draw_action(t_fractal *frac, int flag);
void	draw_content(t_fractal *frac, int x, int y, int flag);
/* fractals variations */
double	mandelbrot(t_fractal *frac, int x, int y);
double	julia(t_fractal *frac, int x, int y, t_complex *c);
/* julia - change parameters */
void	julia_list(t_fractal *frac, t_list **head);
/* control hooks */
void	change_sets(t_fractal *frac, t_list **list, t_list *head);
void	key_hook(int keycode, t_fractal *frac);
int		handle_key(int keycode, t_fractal *frac);
void	key_fractal_utils(int keycode, t_fractal *frac);
int		handle_mouse(int keycode, int x, int y, t_fractal *frac);
/* colors */
double	smooth_coloring(t_complex *c, double x, double y, double k);
void	get_color(double mu, t_fractal *frac, t_list **head);
/* utils - help messages and put pixel */
int		my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
void	list_fractal_commands(t_fractal *frac);
void	list_window_commands(t_fractal *frac);
void	print_help(t_fractal *frac);
/* free, no leaks */
int		freeall(t_fractal *fractal);
int		close_game(t_fractal *fractal);

#endif