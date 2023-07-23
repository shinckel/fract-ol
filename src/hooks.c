/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/23 20:47:26 by shinckel         ###   ########.fr       */
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

int	close_win(t_fractal *fractal)
{
	// missing free fractal structures
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_fractal *frac)
{
	if (keycode == ESC_KEY)
		close_win(frac);
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
		frac->yarrow -= 30;
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
