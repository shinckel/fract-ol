/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/08 18:44:19 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_fractal *frac, int x, int y)
{
	double		mu;

	frac->c->mset[0] = (x + frac->xarrow)
		/ frac->zoom * (0.47 + 2.0) / (WIDTH - 1) - 2.0;
	frac->c->mset[1] = (y + frac->yarrow)
		/ frac->zoom * (1.12 + 1.12) / (WIDTH - 1) - 1.12;
	mu = smooth_coloring(frac->c->mset, 0, 0, 0);
	return (mu);
}

void	julia_list_of_arrays(t_fractal *frac)
{
	frac->c = malloc(sizeof(t_complex));
	frac->c->jset[0][0] = -0.8;
	frac->c->jset[0][1] = 0.156;
	frac->c->jset[1][0] = 0.285;
	frac->c->jset[1][1] = 0.01;
	frac->c->jset[2][0] = 0.0;
	frac->c->jset[2][1] = 0.8;
	frac->c->jset[3][0] = -0.1;
	frac->c->jset[3][1] = 0.651;
	frac->c->jset[4][0] = -0.70176;
	frac->c->jset[4][1] = -0.3842;
	frac->c->pset[0] = 0.5667;
	frac->c->pset[1] = 0;
}

double	julia(t_fractal *frac, int x, int y, double *num)
{
	double		mu;
	double		ratio;
	double		xaxis;
	double		yaxis;

	if (WIDTH < HEIGHT)
		ratio = HEIGHT * frac->zoom;
	else
		ratio = WIDTH * frac->zoom;
	xaxis = frac->radius * ((x + frac->xarrow) - WIDTH / 2.0) / ratio;
	yaxis = frac->radius * ((y + frac->yarrow) - HEIGHT / 2.0) / ratio;
	if (!ft_strncmp(frac->name, "phoenix", 7))
		mu = smooth_coloring(frac->c->pset, xaxis, yaxis, -0.5);
	else
		mu = smooth_coloring(num, xaxis, yaxis, 0);
	return (mu);
}
