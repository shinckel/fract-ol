/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/01 11:52:25 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	my_mlx_pixel_put(fractal *frac, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = frac->addr + (y * frac->line_length + x
// 			* (frac->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// 	return (0);
// }

void	draw_frac(fractal *frac, char *name)
{
	int		x;
	int		y;
	int		pixel_color;
	color	color;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (!ft_strncmp(name, "mandelbrot", 10))
				color = mandelbrot(frac, x, y);
			else if(!ft_strncmp(name, "julia", 5))
				color = julia(frac, x, y);
			pixel_color = (color.r << 16) + (color.g << 8) + color.b;
			mlx_pixel_put(frac->mlx, frac->win, x, y, pixel_color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv) 
{
	fractal	frac;

	if (argc == 2)
	{
		frac.mlx = mlx_init();
		if (!frac.mlx)
		{
			write(1, MINILIBX, ft_strlen(MINILIBX));
			return (1);
		}
		frac.win = mlx_new_window(frac.mlx, WIDTH,
				HEIGHT, argv[1]);
		draw_frac(&frac, argv[1]);
		mlx_key_hook(frac.win, deal_keys, &frac);
		mlx_loop(frac.mlx);
	}
	write(1, PARAM, ft_strlen(PARAM));
    return (0);
}
