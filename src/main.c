/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/03 18:22:14 by shinckel         ###   ########.fr       */
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

void	draw_frac(t_fractal *frac, char *name, int flag)
{
	int		x;
	int		y;
	int		pixel_color;
	double	smooth;
	t_color	color;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (!ft_strncmp(name, "mandelbrot", 10))
				smooth = mandelbrot(frac, x, y);
			else if(!ft_strncmp(name, "julia", 5))
				smooth = julia(frac, x, y);
			color = get_color(smooth, flag);
			pixel_color = (int)((color.r << 16) + (color.g << 8) + color.b);
			mlx_pixel_put(frac->mlx, frac->win, x, y, pixel_color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv) 
{
	t_fractal	frac;

	frac.name = argv[1];
	frac.flag = 1;
	if (argc == 2)
	{
		frac.mlx = mlx_init();
		if (!frac.mlx)
		{
			write(1, MINILIBX, ft_strlen(MINILIBX));
			return (1);
		}
		frac.win = mlx_new_window(frac.mlx, WIDTH,
				HEIGHT, frac.name);
		draw_frac(&frac, frac.name, frac.flag);
		mlx_key_hook(frac.win, key_hook, &frac);
		mlx_loop(frac.mlx);
	}
	write(1, PARAM, ft_strlen(PARAM));
    return (0);
}
