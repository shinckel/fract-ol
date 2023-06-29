/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/29 17:24:28 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Pickover stalk

// while (iter++ < frac->max_iter)

// frac->cx = (x + frac->xarrow) / frac->zoom
// 	* (0.47 + 2.0) / (frac->width) - 2.0;
// frac->cy = (y + frac->yarrow) / frac->zoom
// 	* (1.12 + 1.12) / (frac->width) - 1.12;

// set cx and cy to the complex plane pixels
// total range (but only showing positives)
// 0 * ((0.47 + 2.0) / 1280) = 0
// 1280 * ((0.47 + 2.0) / 1280) = 0.47 + 2.0 = 2.47
// now, with negatives
// 0 * ((0.47 + 2.0) / 1280) - 2.0 = -2.0
// 1280 * ((0.47 + 2.0) / 1280) - 2.0 = 0.47
void	mandelbrot(t_fractal *frac, int x, int y)
{
	double	zx;
	double	zy;
	int		iter;
	float	modulus;
	double	log_iter;
	double	log_normal;

	iter = 0;
	zx = 0.0;
	zy = 0.0;
	frac->cx = x * ((0.47 + 2.0) / frac->width) - 2.0;
	frac->cy = y * ((1.12 + 1.12) / frac->height) - 1.12;
	while (iter++ < frac->max_iter)
	{
		frac->zx_new = zx * zx - zy * zy + frac->cx;
		frac->zy_new = 2 * zx * zy + frac->cy;
		modulus = sqrt(zx * zx + zy * zy);
		zx = frac->zx_new;
		zy = frac->zy_new;
		if (zx * zx + zy * zy > 4.0)
		{
			log_iter = (log(log(modulus))) / log(2.0);
			log_normal = log_iter / frac->max_iter;
			int blue = 0x0000FF;
			int red = 0xFF0000;
			int color = blue + (int)(log_normal * (red - blue));
			mlx_pixel_put(frac->mlx, frac->win, x, y, color);
			break ;
		}
	}
}

void	draw_frac(t_fractal *frac)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < frac->width)
	{
		y = 0;
		while (y < frac->height)
		{
			mandelbrot(frac, x, y);
			y++;
		}
		x++;
	}
}

int	main(void)
{
	t_fractal	frac;

	mandelbrot_param(&frac);
	frac.mlx = mlx_init();
	if (!frac.mlx)
	{
		write(1, MINILIBX, ft_strlen(MINILIBX));
		return (1);
	}
	frac.win = mlx_new_window(frac.mlx, frac.width,
			frac.height, frac.name);
	draw_frac(&frac);
	mlx_key_hook(frac.win, deal_keys, &frac);
	mlx_loop(frac.mlx);
	return (0);
}
