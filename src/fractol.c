/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/10 22:21:32 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 1st mandatory -> Mandelbrot set
// 2nd mandatory -> Julia set
// Turtle
// Island
// Xquartz

#include "fractol.h"

int deal_keys(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(1);
	}
	return (0);
}

int	main(void)
{
    t_fractal fractal;

	fractal.width = 600;
	fractal.height = 800;
	fractal.name = "Sofia";
	int bg_color = 0xFFC0CB;

	fractal.mlx = mlx_init();
	if (!fractal.mlx) {
		printf("Failed to initialize MiniLibX.\n");
		return (1);
	}
	fractal.win = mlx_new_window(fractal.mlx, fractal.width, fractal.height, fractal.name);
	for (int x = 0; x < 50; x++)
	{
		for (int y = 0; y < 50; y++)
			mlx_pixel_put(fractal.mlx, fractal.win, x, y, bg_color);
	}
	mlx_key_hook(fractal.win, deal_keys, &fractal);
	mlx_loop(fractal.mlx);
	return (0);
}
