/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/29 14:08:04 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Here I am working with a mathematical width of 3
void	mandelbrot_param(t_fractal *frac)
{
	frac->width = 720;
	frac->height = 720;
	// frac->min_x = -2.0;
	// frac->max_x = 2.0;
	// frac->min_y = -2.0;
	// frac->max_y = 2.0;
	frac->max_iter = 1000;
	frac->zoom = 1;
	frac->xarrow = 0;
	frac->yarrow = 0;
	frac->name = "Mandelbrot Set";
}

void	julia_param(t_fractal *frac)
{
    frac->width = 1280;
    frac->height = 720;
    frac->min_x = -2.0;
    frac->max_x = 2.0;
    frac->min_y = -2.0;
    frac->max_y = 2.0;
    frac->max_iter = 1000;
    frac->zoom = 1;
    frac->xarrow = 0;
    frac->yarrow = 0;
    frac->color = 0xFFFFFF;
    frac->name = "Julia Set";
}
