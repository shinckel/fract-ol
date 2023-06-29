/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:18:55 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/16 14:24:09 by shinckel         ###   ########.fr       */
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

typedef struct s_fractal {

	void		*mlx;
	void		*win;
	int			width;
	int			height;
	double		min_x;
	double		max_x;
	double		min_y;
	double		max_y;
	double		step_x;
	double		step_y;
	double		cx;
	double		cy;

	double		zoom;

	double		x2;
	double		y2;
	double		tmp;

	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;

	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_fractal;

int 	deal_keys(int keycode, t_fractal *fractal);
double	distanceEstimator(t_fractal *fractal);

#endif