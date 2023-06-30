/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:07:13 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/30 23:21:26 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(fractal *frac)
{
	double	zx;
	double	zy;
	int		iter;

	iter = 0;
	zx = 0.0;
	zy = 0.0;
	while (iter++ < MAX_ITER)
	{
		frac->new1 = zx * zx - zy * zy + 0.5;
		frac->new2 = 2 * zx * zy + 0.193;
		zx = frac->new1;
		zy = frac->new2;
	}
	return (iter);
}

color julia(fractal *frac, int x, int y)
{
	int		iter;
	double	smooth;
	color	color_effect;

	frac->cx = x * ((1.20 + 1.00) / WIDTH) - 1.20;
	frac->cy = y * ((1.12 + 1.12) / HEIGHT) - 1.12;
	iter = julia_iter(frac);
	smooth = smoothColoring(iter, frac);
	color_effect = getColor(smooth);
	return (color_effect);
}