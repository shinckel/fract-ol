/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:28 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/03 11:06:12 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double smooth_coloring(t_fractal *frac, double x, double y) 
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
			// smooth /= 5.18;
            break;
        }
        temp = zx * zx - zy * zy + frac->cx;
        zy = 2 * zx * zy + frac->cy;
        zx = temp;
    }

    return (smooth);
}

/*
color pallete[] = {
    {255, 255, 0}, // Yellow
    {255, 0, 255}  // Magenta
    // Add more pallete as needed
};
*/

// color getColor(double smoothCount)
// {
// 	color	color;
// 	int		clr1;
// 	int		clr2;
// 	double	t1;
// 	double	t2;

// 	printf("%f\n", smoothCount);
// 	clr1 = (int)smoothCount;
// 	t2 = smoothCount - clr1;
// 	t1 = 1 - t2;
// 	clr1 = clr1 % 6;
// 	clr2 = (clr1 + 1) % 6;
// 	color.r = (pallete[clr1].r * t1 + pallete[clr2].r * t2);
// 	color.g = (pallete[clr1].g * t1 + pallete[clr2].g * t2);
//     color.b = (pallete[clr1].b * t1 + pallete[clr2].b * t2);
// 	return (color);
// }


t_color	get_color(double smoothCount, int flag)
{
	t_color	color;

	if (flag == 1)
	{
		color.r = (int)(smoothCount * 25) % 256;
		color.g = (int)(smoothCount * 1) % 256;
		color.b = (int)(smoothCount * 20) % 256;
	}
	else if (flag == 2)
	{
		color.r = (int)((smoothCount) * 1) % 256;
		color.g = (int)(log(smoothCount) * 25) % 256;
		color.b = (int)((smoothCount) * 15) % 256;
	}
	else if (flag == 3)
	{
		color.r = (int)(255 * (1 + cos(2 * M_PI * log(smoothCount) / 13)) / 2);
		color.g = (int)(255 * (1 + cos(2 * M_PI * log(smoothCount) / 13)) / 2);
		color.b = (int)(255 * (1 + cos(2 * M_PI * log(smoothCount) / 13)) / 2);
	}
	return (color);
}