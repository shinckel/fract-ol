/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/28 21:40:59 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//Pickover stalk

// adjust the complex plane to match the aspect ratio of the window
// where will be the coordinates x and y? what is the size of each unit?


// void	put_some_color(t_fractal *fractal, int inter, int x, int y)
// {
// 	if (inter < 10)
// 	{

// 	}
// }

// set cx and cy to the complex plane pixels
// iterate over the complex variable zx and zy until max_iterations
void	mandelbrot(t_fractal *fractal, int x, int y)
{
	// double zx;
    // double zy;
    // int iter;
	
	// fractal->cx = fractal->min_x + fractal->unit_x * x;
    //         fractal->cy = fractal->min_y + fractal->unit_y * y;
	// zx = 0.0;
	// zy = 0.0;
	// iter = 0;
	// while (iter < fractal->max_iter)
	// {
	// 	fractal->zx_new = zx * zx - zy * zy + fractal->cx;
	// 	fractal->zy_new = 2 * zx * zy + fractal->cy;
	// 	zx = fractal->zx_new;
	// 	zy = fractal->zy_new;
	// 	if (zx * zx + zy * zy > 4.0)
	// 	{
	// 		if (iter > 10)
	// 		{
	// 			mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0x370926 * iter);
	// 			break ;
	// 		}
	// 		if (iter > 20)
	// 		{
	// 			mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0xFF595E * iter);
	// 			break ;
	// 		}
	// 		if (iter > 30)
	// 		{
	// 			mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0x1C0118 * iter);
	// 			break ;
	// 		}
	// 		mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0xFF595E * iter);
	// 		break ;
	// 	}
	// 	iter++;
	// }
	// if (iter == fractal->max_iter)
	// 	mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0x42113C);

	int		i;
	double	z0;
	double	z1;
	double	tempz0;

	i = 0;
	fractal->cx = (x + fractal->xarrow) / fractal->zoom
		* (0.47 + 2.0) / (fractal->width - 1) - 2.0;
	fractal->cy = (y + fractal->yarrow) /fractal->zoom
		* (1.12 + 1.12) / (fractal->width - 1) - 1.12;
	z0 = fractal->cx;
	z1 = fractal->cy;
	while (i++ < fractal->max_iter)
	{
		tempz0 = z0 * z0 - z1 * z1 + fractal->cx;
		z1 = 2.0 * z0 * z1 + fractal->cy;
		z0 = tempz0;
		if (z0 * z0 + z1 * z1 > 4)
		{
			mlx_pixel_put(fractal->mlx, fractal->win, x, y, 0x42113C * i);
			break ;
		}
	}
}

void draw_fractal(t_fractal *fractal)
{
    int x;
    int y;

    x = 0;
	y = 0;
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
