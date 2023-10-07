/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/07 18:25:05 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// circular linked list
void	change_sets(t_list **headRef, t_list *head)
{
	if (*headRef == NULL)
		return ;

	printf("i am herer with : %p\n", *headRef);
	if ((*headRef)->next == NULL)
		(*headRef)->next = head;
	else
		*headRef = (*headRef)->next;
}

void	key_hook(int keycode, t_fractal *frac)
{
	if (keycode == ESC_KEY)
		close_game(frac);
	else if (keycode == SPACE)
		change_sets(&frac->list, frac->head);
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

int	handle_key(int keycode, t_fractal *frac)
{
	key_hook(keycode, frac);
	key_fractal_utils(keycode, frac);
	return (0);
}

// static void	ft_zoom(double x, double y, t_fractal *frac)
// {
// 	frac->x2 = (x / frac->zoom) - (x / (frac->zoom * 1.3));
// 	frac->y2 = (y / frac->zoom) - (y / (frac->zoom * 1.3));
// 	frac->zoom *= 1.3;
// 	frac->iterations++;
// }

// static void	ft_dezoom(double x, double y, t_fractal *frac)
// {
// 	frac->x2 = (x / frac->zoom) - (x / (frac->zoom / 1.3));
// 	frac->y2 = (y / frac->zoom) - (y / (frac->zoom / 1.3));
// 	frac->zoom /= 1.3;
// 	frac->iterations--;
// }

// int		handle_mouse(int keycode, int x, int y, t_fractal *frac)
// {
// 	if (keycode == 4)
// 		ft_zoom();
// 	else if (keycode == 5)
// 		ft_dezoom();
// 	return (0);
// }