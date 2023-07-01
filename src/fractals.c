/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/01 19:52:55 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

color mandelbrot(fractal *frac, int x, int y)
{
	double	smooth;
	color	color_effect;

	frac->cx = x * ((0.47 + 2.0) / WIDTH) - 2.0;
	frac->cy = y * ((1.12 + 1.12) / HEIGHT) - 1.12;
	smooth = smoothColoring(frac, 0, 0);
	color_effect = getColor(smooth);
	return (color_effect);
}

color julia(fractal *frac, int x, int y)
{
	double	smooth;
	double	xaxis;
	double	yaxis;

	color	color_effect;

	xaxis = 3 * (x - WIDTH / 2.0) / WIDTH;
    yaxis = 3 * (y - HEIGHT / 2.0) / HEIGHT;
	//set1
	// frac->cx = -0.7;
	// frac->cy = 0.27015;
	//set 2
	// frac->cx = -0.8;
	// frac->cy = 0.156;
	//set 3
	frac->cx = 0.0;
	frac->cy = 0.8;
	//set 4
	// frac->cx = 0.285;
	// frac->cy = 0.01;
	//set 5
	// frac->cx = - 0.74543;
	// frac->cy = 0.11301;
	smooth = smoothColoring(frac, xaxis, yaxis);
	color_effect = getColor(smooth);
	return (color_effect);
}
