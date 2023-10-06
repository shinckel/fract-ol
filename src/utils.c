/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 11:39:49 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/06 17:42:11 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x
			* (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return (0);
}

void	list_fractal_commands(t_fractal *frac)
{
	mlx_string_put(frac->mlx, frac->win, WIDTH - 200, 40,
		0xF64740, "mandelbrot:                 m");
	mlx_string_put(frac->mlx, frac->win, WIDTH - 200, 55,
		0xF64740, "julia:                      j");
	mlx_string_put(frac->mlx, frac->win, WIDTH - 200, 70,
		0xF64740, "change julia set:       space");
	mlx_string_put(frac->mlx, frac->win, WIDTH - 200, 85,
		0xF64740, "phoenix:                    p");
	mlx_string_put(frac->mlx, frac->win, WIDTH - 200, 100,
		0xF64740, "change color scheme:      tab");
}

void	list_window_commands(t_fractal *frac)
{
	mlx_string_put(frac->mlx, frac->win, 40, 40, 0xF64740,
		"quit:                     esc");
	mlx_string_put(frac->mlx, frac->win, 40, 55, 0xF64740,
		"move around:       arrow keys");
	mlx_string_put(frac->mlx, frac->win, 40, 70, 0xF64740,
		"zoom:     mouse wheel / z / -");
	mlx_string_put(frac->mlx, frac->win, 40, 85, 0xF64740,
		"reset view:                 r");
	mlx_string_put(frac->mlx, frac->win, 40, 100, 0xF64740,
		"toggle zoom follow mouse:   f");
}

void	print_help(t_fractal *frac)
{
	if (frac->help)
	{
		mlx_string_put(frac->mlx, frac->win, 40, 20, 0xF64740,
			"AVAILABLE COMMANDS");
		list_window_commands(frac);
		list_fractal_commands(frac);
	}
	else
		mlx_string_put(frac->mlx, frac->win, WIDTH - 70, HEIGHT - 8,
			0xF64740, "h for help");
}
