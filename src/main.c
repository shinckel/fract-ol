/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/08 14:32:52 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_name(char *str)
{
	if ((!ft_strncmp(str, "mandelbrot", 10) && ft_strlen(str) == 10)
		|| (!ft_strncmp(str, "julia", 5) && ft_strlen(str) == 5)
		|| (!ft_strncmp(str, "phoenix", 7) && ft_strlen(str) == 7))
		return (1);
	return (0);
}

void	draw_action(t_fractal *frac, int flag)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			draw_content(frac, x, y, flag);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	print_help(frac);
}

void	draw_content(t_fractal *frac, int x, int y, int flag)
{
	int	tab;

	tab	= 0;
	if (frac->i == 4)
			frac->i = 0;
	if (!ft_strncmp(frac->name, "mandelbrot", 10))
		frac->mu = mandelbrot(frac, x, y);
	else if (!ft_strncmp(frac->name, "julia", 5)
		|| !ft_strncmp(frac->name, "phoenix", 7))
		frac->mu = julia(frac, x, y, (frac->c->jset[frac->i]));
	tab = get_color(frac->mu, flag);
	if (flag == 1)
		tab = get_color(frac->mu, flag);
	else if (flag > 1)
	{
		tab = get_color(frac->mu, flag);
		frac->flag = -1;
	}
	my_mlx_pixel_put(frac, x, y, tab);
}

void	initialize_params(t_fractal *frac, char *str)
{
	frac->i = 0;
	frac->help = 0;
	frac->flag = 0;
	frac->name = str;
	frac->xarrow = 0;
	frac->yarrow = 0;
	frac->zoom = 1;
	frac->radius = 3;
	frac->iterations = 200;
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bits_per_pixel,
			&frac->line_length, &frac->endian);
}

int	main(int argc, char **argv)
{
	t_fractal	frac;

	if (argc == 2 && check_name(argv[1]))
	{
		frac.mlx = mlx_init();
		if (!frac.mlx)
		{
			write(1, MINILIBX, ft_strlen(MINILIBX));
			return (1);
		}
		initialize_params(&frac, argv[1]);
		julia_list_of_arrays(&frac);
		frac.win = mlx_new_window(frac.mlx, WIDTH, HEIGHT, frac.name);
		draw_action(&frac, 0);
		mlx_key_hook(frac.win, handle_key, &frac);
		mlx_hook(frac.win, 17, 1L << 0, close_game, &frac);
		mlx_mouse_hook(frac.win, handle_mouse, &frac);
		mlx_loop(frac.mlx);
	}
	else
		write(1, PARAM, ft_strlen(PARAM));
	return (0);
}
