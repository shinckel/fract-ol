/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/28 11:24:57 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Calculate the aspect ratio of the window and the complex plane
void	mandelbrot_param(t_fractal *fractal)
{
	fractal->width = 720;
	fractal->height = 720;
	fractal->min_x = -2.0;
    fractal->max_x = 2;
    fractal->min_y = -2.0;
	fractal->max_y = 2.0;
	fractal->max_iter = 1000;
	fractal->zoom = 1;
	fractal->xarrow = 0;
	fractal->yarrow = 270;
	fractal->color = 0xFFFFFF;
	fractal->name = "Mandelbrot Set";
}

void	julia_param(t_fractal *fractal)
{
    fractal->width = 1280;
    fractal->height = 720;
    fractal->min_x = -2.0;
    fractal->max_x = 2.0;
    fractal->min_y = -2.0;
    fractal->max_y = 2.0;
    fractal->max_iter = 1000;
    fractal->zoom = 1;
    fractal->xarrow = 0;
    fractal->yarrow = 0;
    fractal->color = 0xFFFFFF;
    fractal->name = "Julia Set";
}
