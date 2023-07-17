/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/14 19:18:24 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
double want_aspect = (m_Ymax - m_Ymin) / (m_Xmax - m_Xmin);
            double picCanvas_aspect = picCanvas.ClientSize.Height / (double)picCanvas.ClientSize.Width;
if (want_aspect > picCanvas_aspect)
            {
                // The selected area is too tall and thin.
                // Make it wider.
                wid = (m_Ymax - m_Ymin) / picCanvas_aspect;
                mid = (m_Xmin + m_Xmax) / 2;
                m_Xmin = mid - wid / 2;
                m_Xmax = mid + wid / 2;
            } else {
                // The selected area is too short and wide.
                // Make it taller.
                hgt = (m_Xmax - m_Xmin) * picCanvas_aspect;
                mid = (m_Ymin + m_Ymax) / 2;
                m_Ymin = mid - hgt / 2;
                m_Ymax = mid + hgt / 2;
            }
        }
*/

/*
void	julia_params(t_complex_c *c1, t_complex_c *c2, t_complex_c *c3, t_complex_c *c4)
{
	c1->x = -0.0;
	c1->y = 0.27015;
	c2->x = -0.8;
	c2->y = 0.156;
	c3->x = 0.0;
	c3->y = 0.8;
	c4->x = 0.285;
	c4->y = 0.01;
	// c5.x = - 0.74543;
	// c5.y = 0.11301;
	// c6.x = 0.355;
	// c6.y = 0.355;
}
*/

double mandelbrot(int x, int y)
{
	double	smooth;
	t_complex_c	c;

	c.x = x * ((0.47 + 2.0) / WIDTH) - 2.0;
	c.y = y * ((1.12 + 1.12) / HEIGHT) - 1.12;
	smooth = smooth_coloring(&c, 0, 0);
	return (smooth);
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

double julia(int x, int y, t_complex_c *c)
{
	double	smooth;
	double	xaxis;
	double	yaxis;

	xaxis = 3 * (x - WIDTH / 2.0) / WIDTH;
    yaxis = 3 * (y - HEIGHT / 2.0) / HEIGHT;
	smooth = smooth_coloring(c, xaxis, yaxis);
	return (smooth);
}
