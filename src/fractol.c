/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/15 14:12:17 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1st mandatory -> Mandelbrot set
// 2nd mandatory -> Julia set
// Turtle
// Island
// Xquartz

#include "fractol.h"

// width = 600px -> for each pixel in the x-direction, the x-value in the complex plane should change by approximately 0.0066666667
void	map_screen(t_fractal *fractal)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	fractal->min_x = -2.0;
	fractal->max_x = 2.0;
	fractal->min_y = -2.0;
	fractal->max_y = 2.0;
	fractal->step_x = (fractal->max_x - fractal->min_x) / fractal->width;
	fractal->step_y = (fractal->max_y - fractal->min_y) / fractal->height;
	while (x <= fractal->width)
	{
		while (y <= fractal->height)
		{
			fractal->cx = ;
			fractal->cy = ;
			y++;
		}
		x++;
	}
}

int	main(void)
{
    t_fractal fractal;

	fractal.width = 600;
	fractal.height = 800;
	int bg_color = 0xFFC0CB;

	fractal.mlx = mlx_init();
	if (!fractal.mlx) {
		printf("Failed to initialize MiniLibX.\n");
		return (1);
	}
	fractal.win = mlx_new_window(fractal.mlx, fractal.width, fractal.height, "fract-ol");
	for (int x = 0; x < 50; x++)
	{
		for (int y = 0; y < 50; y++)
			mlx_pixel_put(fractal.mlx, fractal.win, x, y, bg_color);
	}
	mlx_key_hook(fractal.win, deal_keys, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
