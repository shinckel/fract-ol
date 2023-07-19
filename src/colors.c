/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pallete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:13:28 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/03 11:06:12 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double smooth_coloring(t_complex_c	*c, double x, double y)
{
    double	mu;
    double	zx;
	double	zy;
    double	temp;
    int i;

	i = 0;
	zx = 0.0 + x;
	zy = 0.0 + y;
	mu = MAX_ITER;
    while (i++ < MAX_ITER)
	{
        if (zx * zx + zy * zy >= 4.0) {
            mu = i - log(log(sqrt(zx * zx + zy * zy))) / log(2);
            break;
        }
        temp = zx * zx - zy * zy + c->x;
        zy = 2 * zx * zy + c->y;
        zx = temp;
    }

    return (mu);
}

void	get_color(double mu, t_fractal *frac, t_list **head)
{
	t_list	*node;
	int		rgb1;
	int		rgb2;
	int		rgb3;

	rgb1 = ((int)(mu * 25) % 255) << 16;
	rgb1 |= ((int)(mu * 1) % 255) << 8;
	rgb1 |= (int)(mu * 20) % 255;
	rgb2 = ((int)((mu) * 1) % 255) << 16;
	rgb2 |= ((int)(log(mu) * 25) % 255) << 8;
	rgb2 |= (int)((mu) * 15) % 256;
	rgb3 = ((int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 16;
	rgb3 |= (int)((255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 8;
	rgb3 |= (int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2);

	node = ft_lstnew(&rgb3);
	ft_lstadd_front(&node, ft_lstnew(&rgb2));
	ft_lstadd_front(&node, ft_lstnew(&rgb1));
	*head = node;
	frac->head_color = *head;
}
