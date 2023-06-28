/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/28 16:40:16 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Pickover stalk

// adjust the complex plane to match the aspect ratio of the window
// where will be the coordinates x and y? what is the size of each unit?
void	aspect_ratio(t_fractal *fractal)
{
	double	diff;
	double	range_y;
	double	range_x;

	range_x = (fractal->max_x - fractal->min_x);
	range_y = (fractal->max_y - fractal->min_y);
	fractal->win_ratio = fractal->width / fractal->height;
	fractal->plane_ratio = range_x / range_y;
    if (fractal->win_ratio > fractal->plane_ratio)
	{
        fractal->plane_width = range_y * fractal->win_ratio;
        diff = (fractal->plane_width - range_x) / 2;
        fractal->min_x -= diff;
        fractal->max_x += diff;
    } else {
        fractal->plane_height = range_x / fractal->win_ratio;
        diff = (fractal->plane_height - range_y) / 2;
        fractal->min_y -= diff;
        fractal->max_y += diff;
    }
    fractal->unit_x = (fractal->max_x - fractal->min_x) / fractal->width;
    fractal->unit_y = (fractal->max_y - fractal->min_y) / fractal->height;
}

// set cx and cy to the complex plane pixels
// iterate over the complex variable zx and zy until max_iterations
void	mandelbrot(t_fractal *fractal, int x, int y)
{
	double zx;
    double zy;
    int iter;
	
	fractal->cx = fractal->min_x + fractal->unit_x * x;
            fractal->cy = fractal->min_y + fractal->unit_y * y;
	zx = 0.0;
	zy = 0.0;
	iter = 0;
	while (iter < fractal->max_iter)
	{
		fractal->zx_new = zx * zx - zy * zy + fractal->cx;
		fractal->zy_new = 2 * zx * zy + fractal->cy;
		zx = fractal->zx_new;
		zy = fractal->zy_new;
		if (zx * zx + zy * zy > 4.0)
		{
			mlx_pixel_put(fractal->mlx, fractal->win, x, y, fractal->color);
			break ;
		}
		iter++;
	}
	if (iter == fractal->max_iter)
		mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0x000000);
}

void draw_fractal(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
	y = 0;
    aspect_ratio(fractal);
    while (x < fractal->width)
    {
		y = 0;
        while (y < fractal->height)
        {
			mandelbrot(fractal, x, y);
            y++;
        }
        x++;
    }
}

int main(void)
{
    t_fractal fractal;

	mandelbrot_param(&fractal);
    fractal.mlx = mlx_init();
    if (!fractal.mlx) {
        write(1, MINILIBX, ft_strlen(MINILIBX));
        return (1);
    }
    fractal.win = mlx_new_window(fractal.mlx, fractal.width, fractal.height, fractal.name);
    draw_fractal(&fractal);
    mlx_key_hook(fractal.win, deal_keys, &fractal);
    mlx_loop(fractal.mlx);
    return (0);
}
