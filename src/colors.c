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
    double smooth;
    double	zx;
	double	zy;
    double temp;
    int i;

	i = 0;
	zx = 0.0 + x;
	zy = 0.0 + y;
	smooth = MAX_ITER;
    while (i++ < MAX_ITER)
	{
        if (zx * zx + zy * zy >= 4.0) {
            smooth = i - log(log(sqrt(zx * zx + zy * zy))) / log(2);
			// smooth /= 5.18;
            break;
        }
        temp = zx * zx - zy * zy + c->x;
        zy = 2 * zx * zy + c->y;
        zx = temp;
    }

    return (smooth);
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
	rgb2 = ((int)((mu) * 1) % 256) << 16;
	rgb2 |= ((int)(log(mu) * 25) % 256) << 8;
	rgb2 |= (int)((mu) * 15) % 256;
	rgb3 = ((int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 16;
	rgb3 |= (int)((255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 8;
	rgb3 |= (int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2);

	node = ft_lstnew(&rgb1);
	ft_lstadd_front(&node, ft_lstnew(&rgb2));
	ft_lstadd_front(&node, ft_lstnew(&rgb3));
	*head = node;
	frac->head_color = *head;
}


/*
color pallete[] = {
    {255, 255, 0}, // Yellow
    {255, 0, 255}  // Magenta
    // Add more pallete as needed
};
*/

// color getColor(double mu)
// {
// 	color	color;
// 	int		clr1;
// 	int		clr2;
// 	double	t1;
// 	double	t2;

// 	printf("%f\n", mu);
// 	clr1 = (int)mu;
// 	t2 = mu - clr1;
// 	t1 = 1 - t2;
// 	clr1 = clr1 % 6;
// 	clr2 = (clr1 + 1) % 6;
// 	color.r = (pallete[clr1].r * t1 + pallete[clr2].r * t2);
// 	color.g = (pallete[clr1].g * t1 + pallete[clr2].g * t2);
//     color.b = (pallete[clr1].b * t1 + pallete[clr2].b * t2);
// 	return (color);
// }