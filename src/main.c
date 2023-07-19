/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/19 21:43:17 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_frac(t_fractal *frac, int flag)
{
    int x;
    int y;
    double mu;

    x = 0;
    y = 0;
    while (x < WIDTH)
    {
        y = 0;
        while (y < HEIGHT)
        {
            if (!ft_strncmp(frac->name, "mandelbrot", 10))
                mu = mandelbrot(frac, x, y);
            else if (!ft_strncmp(frac->name, "julia", 5))
                mu = julia(frac, x, y, frac->list->content);
            get_color(mu, frac, &frac->list_color);
			if (flag == 1)
				change_sets(frac, &frac->list_color, frac->head_color);
            if (flag > 1)
            {
				frac->list_color = frac->list_color->next;
				change_sets(frac, &frac->list_color, frac->head_color);
				frac->flag = -1;
            }
			mlx_pixel_put(frac->mlx, frac->win, x, y, *(int *)frac->list_color->content);
            y++;
        }
        x++;
    }
}

int main(int argc, char **argv)
{
    t_fractal frac;

    frac.list = NULL;
    frac.list_color = NULL;
	frac.flag = 0;
    frac.name = argv[1];
	frac.xarrow = 0;
	frac.yarrow = 0;
	frac.zoom = 1;
	frac.radius = 3;
    julia_list(&frac, &frac.list);
    if (argc == 2)
    {
        frac.mlx = mlx_init();
        if (!frac.mlx)
        {
            write(1, MINILIBX, ft_strlen(MINILIBX));
            return (1);
        }
        frac.win = mlx_new_window(frac.mlx, WIDTH, HEIGHT, frac.name);
        draw_frac(&frac, 0);
        mlx_key_hook(frac.win, key_hook, &frac);
        mlx_loop(frac.mlx);
    }
    write(1, PARAM, ft_strlen(PARAM));
    return (0);
}
