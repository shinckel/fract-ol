/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:28 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/08 14:31:22 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	smooth_coloring(double *num, double x, double y, double k)
{
	t_complex	z;
	double		z_minus1[2];
	t_fractal	frac;
	int			i;

	i = 0;
	frac.iterations = MAX_ITER;
	frac.mu = frac.iterations;
	z_minus1[0] = num[0];
	z_minus1[1] = num[1];
	z.x = x;
	z.y = y;
	while (i++ < frac.iterations)
	{
		if (z.x * z.x + z.y * z.y >= 4.0)
		{
			frac.mu = i - log(log(sqrt(z.x * z.x + z.y * z.y))) / log(2);
			break ;
		}
		frac.zx = z.x;
		frac.zy = z.y;
		z.x = frac.zx * frac.zx - frac.zy * frac.zy + num[0] + k * z_minus1[0];
		z.y = 2 * frac.zx * frac.zy + num[1] + k * z_minus1[1];
		z_minus1[0] = frac.zx;
		z_minus1[1] = frac.zy;
	}
	return (frac.mu);
}

int	get_color(double mu, int flag)
{
	int		rgb1;
	int		rgb2;
	int		rgb3;

	rgb1 = ((int)(mu * 25) % 256) << 16;
	rgb1 |= ((int)(mu * 1) % 256) << 8;
	rgb1 |= (int)(mu * 20) % 256;
	rgb2 = ((int)(mu * 1) % 256) << 16;
	rgb2 |= ((int)(mu * 4) % 256) << 8;
	rgb2 |= (int)(mu * 15) % 256;
	rgb3 = ((int)(256 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 16;
	rgb3 |= (int)((256 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 8;
	rgb3 |= (int)(256 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2);
	if (!flag)
		return (rgb1);
	else if (flag == 1)
		return (rgb2);
	else
		return (rgb3);
}
