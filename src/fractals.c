/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/07 19:43:40 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_fractal *frac, int x, int y)
{
	double		mu;
	t_complex	c;

	c.x = (x + frac->xarrow) / frac->zoom * (0.47 + 2.0) / (WIDTH - 1) - 2.0;
	c.y = (y + frac->yarrow) / frac->zoom * (1.12 + 1.12) / (WIDTH - 1) - 1.12;
	mu = smooth_coloring(&c, 0, 0, 0);
	return (mu);
}

void	julia_list(t_fractal *frac, t_list **headRef, t_list **head)
{
	frac->sets->jset[1][1] = -0.8;
	frac->sets->jset[1][2] = 0.156;
	frac->sets->jset[2][1] = 0.285;
	frac->sets->jset[2][2] = 0.01;
	frac->sets->jset[3][1] = 0.0;
	frac->sets->jset[3][2] = 0.8;
	frac->sets->jset[4][1] = -0.1;
	frac->sets->jset[4][2] = 0.651;
	*headRef = ft_lstnew(frac->sets->jset[1]);
	ft_lstadd_front(headRef, ft_lstnew(frac->sets->jset[2]));
	ft_lstadd_front(headRef, ft_lstnew(frac->sets->jset[3]));
	ft_lstadd_front(headRef, ft_lstnew(frac->sets->jset[4]));
	*head = *headRef;
}

double	julia(t_fractal *frac, int x, int y)
{
	double		mu;
	double		ratio;
	double		xaxis;
	double		yaxis;
	// t_complex	*phoenix;

	// phoenix = malloc(sizeof(t_complex));
	// phoenix->x = 0.5667;
	// phoenix->y = 0;
	if (WIDTH < HEIGHT)
		ratio = HEIGHT * frac->zoom;
	else
		ratio = WIDTH * frac->zoom;
	xaxis = frac->radius * ((x + frac->xarrow) - WIDTH / 2.0) / ratio;
	yaxis = frac->radius * ((y + frac->yarrow) - HEIGHT / 2.0) / ratio;
	// if (!ft_strncmp(frac->name, "phoenix", 7))
	// 	mu = smooth_coloring(phoenix, xaxis, yaxis, -0.5);
	// else
	mu = smooth_coloring(frac, xaxis, yaxis, 0);
	return (mu);
}

// void	print_list(t_list *list)
// {
// 	t_list *current = list;

// 	while (current != NULL)
// 	{
// 		t_complex *complex = (t_complex *)current->content;
// 		printf("cx: %lf, cy: %lf\n", complex->x, complex->y);
// 		current = current->next;
// 	}
// }

// c5->x = -0.70176;
// c5->y = -0.3842;