/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:28 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/01 19:53:05 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double smoothColoring(fractal *frac, double x, double y) 
{
    double smooth;
    double	zx;
	double	zy;
    double temp;
    int i;

	i = 0;
	zx = 0.0 + x;
	zy = 0.0 + y;
	smooth = MAX_ITER;
    while (i++ < MAX_ITER)
	{
        if (zx * zx + zy * zy >= 4.0) {
            smooth = i - log(log(sqrt(zx * zx + zy * zy))) / log(2);
            break;
        }
        temp = zx * zx - zy * zy + frac->cx;
        zy = 2 * zx * zy + frac->cy;
        zx = temp;
    }

    return (smooth);
}

// 25 1 20
color getColor(double smoothCount) 
{
    color color;
	//set 1 - pink
    // color.r = (int)(smoothCount * 25) % 256;
    // color.g = (int)(smoothCount * 1) % 256;
    // color.b = (int)(smoothCount * 20) % 256;
	//set 2 - blue
	// color.r = (int)((smoothCount) * 1) % 256;
    // color.g = (int)(log(smoothCount) * 25) % 256;
    // color.b = (int)((smoothCount) * 15) % 256;
	//set 3 - black and white
	color.r = (int)(255 * (1 + cos(2 * M_PI * log(smoothCount) / 13)) / 2);
    color.g = (int)(255 * (1 + cos(2 * M_PI * log(smoothCount) / 13)) / 2);
    color.b = (int)(255 * (1 + cos(2 * M_PI * log(smoothCount) / 13)) / 2);
    return (color);
}