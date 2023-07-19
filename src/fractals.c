/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/19 21:49:00 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double mandelbrot(t_fractal *frac, int x, int y)
{
	double	mu;
	t_complex_c	c;

	c.x = (x + frac->xarrow) / frac->zoom * (0.47 + 2.0) / (WIDTH - 1) - 2.0;
	c.y = (y + frac->yarrow) / frac->zoom * (1.12 + 1.12) / (WIDTH - 1) - 1.12;
	mu = smooth_coloring(&c, 0, 0);
	return (mu);
}

void print_list(t_list *list)
{
	t_list *current = list;

	while (current != NULL)
	{
		t_complex_c *complex = (t_complex_c *)current->content;
		printf("cx: %lf, cy: %lf\n", complex->x, complex->y);
		current = current->next;
	}
}

void julia_list(t_fractal *frac, t_list **head)
{
	t_list *node;
	t_complex_c *c1;
	t_complex_c *c2;
	t_complex_c *c3;
	t_complex_c *c4;

	c1 = malloc(sizeof(t_complex_c));
	c2 = malloc(sizeof(t_complex_c));
	c3 = malloc(sizeof(t_complex_c));
	c4 = malloc(sizeof(t_complex_c));
	c4 = malloc(sizeof(t_complex_c));
	c1->x = -0.7;
	c1->y = 0.27015;
	c2->x = -0.8;
	c2->y = 0.156;
	c3->x = 0.0;
	c3->y = 0.8;
	c4->x = 0.285;
	c4->y = 0.01;
	node = ft_lstnew(c1);
	ft_lstadd_front(&node, ft_lstnew(c2));
	ft_lstadd_front(&node, ft_lstnew(c3));
	ft_lstadd_front(&node, ft_lstnew(c4));
	*head = node;
	frac->head = *head;
}

double julia(t_fractal *frac, int x, int y, t_complex_c *c)
{
	double	mu;
	double	ratio;
	double	xaxis;
	double	yaxis;

	if (WIDTH < HEIGHT)
		ratio = HEIGHT * frac->zoom;
	else
		ratio = WIDTH * frac->zoom;
	xaxis = 1.3 * frac->radius * ((x + frac->xarrow) - WIDTH / 2.0) / ratio;
    yaxis = 1.3 * frac->radius * ((y + frac->yarrow) - HEIGHT / 2.0) / ratio;
	mu = smooth_coloring(c, xaxis, yaxis);
	return (mu);
}
