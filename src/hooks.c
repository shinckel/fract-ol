/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/08/01 16:51:28 by shinckel         ###   ########.fr       */
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

void	key_hook(int keycode, t_fractal *frac)
{
	if (keycode == ESC_KEY)
		close_game(frac);
	else if (keycode == SPACE)
		change_sets(frac, &frac->list, frac->head);
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
	if (keycode == M || keycode == J || keycode == P || keycode == SPACE)
	{
		if (frac->flag == -1)
			frac->flag = 2;
	}
	if (keycode != ESC_KEY)
		draw_action(frac, frac->flag);
}

void	key_fractal_utils(int keycode, t_fractal *frac)
{
	if (keycode == M)
		frac->name = "mandelbrot";
	else if (keycode == J)
		frac->name = "julia";
	else if (keycode == P)
		frac->name = "phoenix";
	else if (keycode == Z)
		frac->zoom += 0.2;
	else if (keycode == MINUS)
		frac->zoom -= 0.2;
	else if (keycode == R)
	{
		frac->xarrow = 0;
		frac->yarrow = 0;
		frac->zoom = 1;
		write(1, RESET, strlen(RESET));
	}
	else if (keycode == H)
	{
		if (frac->help)
			frac->help = 0;
		else
			frac->help = 1;
	}
}

int	handle_hooks(int keycode, t_fractal *frac)
{
	key_hook(keycode, frac);
	key_fractal_utils(keycode, frac);
	return (0);
}

// int	handle_mouse(int button, t_fractal *frac)
// {
	
// }