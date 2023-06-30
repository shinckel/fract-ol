/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/30 23:19:08 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_iter(fractal *frac)
{
	double	zx;
	double	zy;
	int		iter;

	iter = 0;
	zx = 0.0;
	zy = 0.0;
	while (iter++ < MAX_ITER)
	{
		frac->zx_new = zx * zx - zy * zy + frac->cx;
		frac->zy_new = 2 * zx * zy + frac->cy;
		zx = frac->zx_new;
		zy = frac->zy_new;
	}
	return (iter);
}

color mandelbrot(fractal *frac, int x, int y)
{
	int		iter;
	double	smooth;
	color	color_effect;

	frac->cx = x * ((0.47 + 2.0) / WIDTH) - 2.0;
	frac->cy = y * ((1.12 + 1.12) / HEIGHT) - 1.12;
	iter = mandelbrot_iter(frac);
	smooth = smoothColoring(iter, frac);
	color_effect = getColor(smooth);
	return (color_effect);
}
