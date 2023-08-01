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

double smooth_coloring(t_complex *c, double x, double y, double k)
{
    t_complex	z;
    t_complex	z_minus1;
	double		zx;
	double		zy;
    double		mu;
    int			i;

	i = 0;
	mu = MAX_ITER;
	z_minus1 = *c;
	z.x = x; 
	z.y = y;
    while (i++ < MAX_ITER)
    {
        if (z.x * z.x + z.y * z.y >= 4.0)
        {
            mu = i - log(log(sqrt(z.x * z.x + z.y * z.y))) / log(2);
            break;
        }
		zx = z.x;
        zy = z.y;
        z.x = zx * zx - zy * zy + c->x + k * z_minus1.x;
        z.y = 2 * zx * zy + c->y + k * z_minus1.y;
        z_minus1.x = zx;
		z_minus1.y = zy;
    }
    return (mu);
}

void	get_color(double mu, t_fractal *frac, t_list **head)
{
	t_list	*node;
	int		rgb1;
	int		rgb2;
	int		rgb3;

	rgb1 = ((int)(mu * 25) % 256) << 16;
	rgb1 |= ((int)(mu * 1) % 256) << 8;
	rgb1 |= (int)(mu * 20) % 256;
	rgb2 = ((int)(mu * 1) % 256) << 16;
	rgb2 |= ((int)(mu * 4) % 256) << 8;
	rgb2 |= (int)(mu * 15) % 256;
	rgb3 = ((int)(256 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 16;
	rgb3 |= (int)((256 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 8;
	rgb3 |= (int)(256 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2);

	node = ft_lstnew(&rgb3);
	ft_lstadd_front(&node, ft_lstnew(&rgb2));
	ft_lstadd_front(&node, ft_lstnew(&rgb1));
	*head = node;
	frac->head_color = *head;
}
