/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:28 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/30 22:30:42 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double smoothColoring(int iterations, fractal *frac) 
{
    double smoothCount;
    double	zx;
	double	zy;
    double temp;
    int i;

	i = 0;
	zx = 0.0;
	zy = 0.0;
	smoothCount = iterations;
    while (i < 256)
	{
        if (zx * zx + zy * zy >= 4.0) {
            smoothCount = i - log(log(sqrt(zx * zx + zy * zy))) / log(2);
            break;
        }
        temp = zx * zx - zy * zy + frac->cx;
        zy = 2 * zx * zy + frac->cy;
        zx = temp;
		i++;
    }

    return (smoothCount);
}

// 25 1 20
color getColor(double smoothCount) 
{
    color color;
	
    color.r = (int)(smoothCount * 25) % 256;
    color.g = (int)(smoothCount * 1) % 256;
    color.b = (int)(smoothCount * 20) % 256;
    return (color);
}