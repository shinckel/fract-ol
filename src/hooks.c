/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/19 21:27:50 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void change_sets(t_fractal *frac, t_list **list, t_list *head)
{
	(void)frac;
    if (*list != NULL)
    {
        *list = (*list)->next;
        if (*list == NULL)
            *list = head;
    }
}

int	key_hook(int keycode, t_fractal *frac)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(frac->mlx, frac->win);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == SPACE)
	{
		if (frac->flag == -1)
			frac->flag = 2;
		change_sets(frac, &frac->list, frac->head);
	}
	else if (keycode == TAB)
		++frac->flag;
	else if (keycode == LEFT)
		frac->xarrow -= 30;
	else if (keycode == DOWN)
		frac->yarrow += 30;
	else if (keycode == RIGHT)
		frac->xarrow += 30;
	else if (keycode == UP)
	{
		frac->yarrow -= 30;
		printf("%f\n", frac->yarrow);
	}
	if (keycode != ESC_KEY)
		draw_frac(frac, frac->flag);
	return (0);
}

/*
void	ft_zoom(double x, double y, t_fractal *fractal)
{
	fractal->x = (x / fractal->zoom) - (x / (fractal->zoom * 1.3));
	fractal->y = (y / fractal->zoom) - (y / (fractal->zoom * 1.3));
	fractal->zoom *= 1.3;
	fractal->iterations++;
}

void	ft_dezoom(double x, double y, t_fractal *fractal)
{
	fractal->x = (x / fractal->zoom) - (x / (fractal->zoom / 1.3));
	fractal->y = (y / fractal->zoom) - (y / (fractal->zoom / 1.3));
	fractal->zoom /= 1.3;
	fractal->iterations--;
}

int	close_game(t_fractal *fractal)
{
	freeall(fractal);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		close_game(fractal);
	else if (keycode == LEFT)
		fractal->xarrow -= 30;
	else if (keycode == DOWN)
		fractal->yarrow += 30;
	else if (keycode == RIGHT)
		fractal->xarrow += 30;
	else if (keycode == UP)
		fractal->yarrow -= 30;
	else if (keycode == PLUS)
		fractal->color += 100;
	else if (keycode == MINUS)
		fractal->color -= 100;
	else if (keycode == R)
	{
		ft_printf("Reset time!\n");
		julia_param(fractal, fractal->name);
	}
	else if (keycode == Z)
		fractal->zoom = 1;
	if (keycode != ESC)
		fractalsetup(fractal);
	return (0);
}

int	mouse_hook(int key_code, int x, int y, t_fractal *fractal)
{
	if (key_code == 1 && !ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->c.x = ((double) x / fractal->width * 4 - 2);
		fractal->c.y = ((double) y / fractal->height * 3 - 1.5);
		fractal->zoom = 1;
	}
	else if (key_code == 4)
		ft_zoom(((double) x / fractal->width * 1000 - 500),
			((double) y / fractal->height * 1000 - 500), fractal);
	else if (key_code == 5)
		ft_dezoom(((double) x / fractal->width * 1000 - 500),
			((double) y / fractal->height * 1000 - 500), fractal);
	fractalsetup(fractal);
	return (0);
}
*/



// if (keycode == TAB)
	// {
	// 	if (frac->flag > 1 && frac->flag <= 3)
	// 	{
	// 		frac->flag--;
	// 		draw_frac(frac);
	// 	}
	// }