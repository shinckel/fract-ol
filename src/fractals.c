/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/23 21:00:48 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double mandelbrot(t_fractal *frac, int x, int y)
{
	double	mu;
	t_complex	c;

	c.x = (x + frac->xarrow) / frac->zoom * (0.47 + 2.0) / (WIDTH - 1) - 2.0;
	c.y = (y + frac->yarrow) / frac->zoom * (1.12 + 1.12) / (WIDTH - 1) - 1.12;
	mu = smooth_coloring(&c, 0, 0, 0);
	return (mu);
}

void print_list(t_list *list)
{
	t_list *current = list;

	while (current != NULL)
	{
		t_complex *complex = (t_complex *)current->content;
		printf("cx: %lf, cy: %lf\n", complex->x, complex->y);
		current = current->next;
	}
}

void julia_list(t_fractal *frac, t_list **head)
{
	t_list *node;
	t_complex *c1;
	t_complex *c2;
	t_complex *c3;
	t_complex *c4;
	t_complex *c5;

	c1 = malloc(sizeof(t_complex));
	c2 = malloc(sizeof(t_complex));
	c3 = malloc(sizeof(t_complex));
	c4 = malloc(sizeof(t_complex));
	c4 = malloc(sizeof(t_complex));
	c5 = malloc(sizeof(t_complex));
	c1->x = -0.70176;
	c1->y = -0.3842;
	c2->x = -0.8;
	c2->y = 0.156;
	c3->x = 0.0;
	c3->y = 0.8;
	c4->x = -0.1;
	c4->y = 0.651;
	c5->x = 0.285;
	c5->y = 0.01;
	node = ft_lstnew(c1);
	ft_lstadd_front(&node, ft_lstnew(c2));
	ft_lstadd_front(&node, ft_lstnew(c3));
	ft_lstadd_front(&node, ft_lstnew(c4));
	ft_lstadd_front(&node, ft_lstnew(c5));
	*head = node;
	frac->head = *head;
}

double julia(t_fractal *frac, int x, int y, t_complex *c)
{
	double	mu;
	double	ratio;
	double	xaxis;
	double	yaxis;
	t_complex	*phoenix;

	phoenix = malloc(sizeof(t_complex));
	phoenix->x = 0.5667;
	phoenix->y = 0;
	if (WIDTH < HEIGHT)
		ratio = HEIGHT * frac->zoom;
	else
		ratio = WIDTH * frac->zoom;
	xaxis = frac->radius * ((x + frac->xarrow) - WIDTH / 2.0) / ratio;
    yaxis = frac->radius * ((y + frac->yarrow) - HEIGHT / 2.0) / ratio;
	if (!ft_strncmp(frac->name, "phoenix", 7))
		mu = smooth_coloring(phoenix, xaxis, yaxis, -0.5);
	else
		mu = smooth_coloring(c, xaxis, yaxis, 0);
	return (mu);
}
