/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:55 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/30 10:46:36 by shinckel         ###   ########.fr       */
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

# define ESC_KEY 81
# define RIGHT_ARROW 39
# define LEFT_ARROW 37
# define MINILIBX "\e[1;41m Failed to initialize MiniLibX \e[0m \n"

typedef struct s_fractal {

	void		*mlx;
	void		*win;
	int			width;
	int			height;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		unit_x;
	double		unit_y;
	double		cx;
	double		cy;
	double		zx_new;
	double		zy_new;
	int			max_iter;
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
}				t_fractal;

/* initialize params */
void	mandelbrot_param(t_fractal *fractal);
/* control hooks */
int		deal_keys(int keycode, t_fractal *fractal);

#endif