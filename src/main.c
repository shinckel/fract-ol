/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/10 14:22:32 by shinckel         ###   ########.fr       */
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

int	get_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	draw_frac(t_fractal *frac)
{
	int		x;
	int		y;
	double	smooth;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (!ft_strncmp(frac->name, "mandelbrot", 10))
				smooth = mandelbrot(x, y);
			else if(!ft_strncmp(frac->name, "julia", 5))
				smooth = julia(x, y, frac->list->content);
			get_color(smooth, frac, &frac->list_color);
			frac->pixel_color = *(int *)(frac->list_color->content);
			mlx_pixel_put(frac->mlx, frac->win, x, y, frac->pixel_color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv) 
{
	t_fractal	frac;

	frac.list = NULL;
	frac.name = argv[1];
	frac.flag = 1;
	julia_list(&frac, &frac.list);
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
		draw_frac(&frac);
		mlx_key_hook(frac.win, key_hook, &frac);
		mlx_loop(frac.mlx);
	}
	write(1, PARAM, ft_strlen(PARAM));
    return (0);
}
