/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 14:05:53 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/13 21:20:22 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// int	my_mlx_pixel_put(fractal *frac, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = frac->addr + (y * frac->line_length + x
// 			* (frac->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// 	return (0);
// }


// void update_colors(double mu, t_fractal *frac, t_list **head)
// {
//     t_list *current = *head;
// 	int rgb1;
// 	int rgb2;
// 	int rgb3;

//     while (current != NULL)
//     {
//         if (*((int *)(current->content)) == 1)
//         {
//             rgb1 = ((int)(mu * 25) % 256) << 16;
//             rgb1 |= ((int)(mu * 1) % 256) << 8;
//             rgb1 |= (int)(mu * 20) % 256;
// 			*((int *)(current->content)) = rgb1;
//         }
//         if (*((int *)(current->content)) == 2)
//         {
//             rgb2 = ((int)(mu * 1) % 256) << 16;
//             rgb2 |= ((int)(log(mu) * 25) % 256) << 8;
//             rgb2 |= (int)(mu * 15) % 256;
// 			*((int *)(current->content)) = rgb2;
//         }
//         if (*((int *)(current->content)) == 3)
//         {
//             rgb3 = ((int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 16;
//             rgb3 |= ((int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2)) << 8;
//             rgb3 |= (int)(255 * (1 + cos(2 * M_PI * log(mu) / 13)) / 2);
// 			*((int *)(current->content)) = rgb2;
//         }
//         current = current->next;
//     }
// }

// void	color_list(t_fractal *frac, t_list **head)
// {
// 	t_list	*node;

// 	int rgb1 = 1;
// 	int rgb2 = 2;
// 	int rgb3 = 3;

// 	node = ft_lstnew(&rgb1);
// 	ft_lstadd_front(&node, ft_lstnew(&rgb2));
// 	ft_lstadd_front(&node, ft_lstnew(&rgb3));
// 	*head = node;
// 	printf("%i\n", *((int *)(*head)->content));
// 	frac->head_color = *head;
// }

void	draw_frac(t_fractal *frac)
{
	int		x;
	int		y;
	double	mu;

	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			if (!ft_strncmp(frac->name, "mandelbrot", 10))
				mu = mandelbrot(x, y);
			else if(!ft_strncmp(frac->name, "julia", 5))
				mu = julia(x, y, frac->list->content);
			get_color(mu, frac, &frac->list_color);
			frac->pixel_color = *(int *)(frac->list_color->content);
			mlx_pixel_put(frac->mlx, frac->win, x, y, frac->pixel_color);
			y++;
		}
		x++;
	}
}

int	main(int argc, char **argv) 
{
	t_fractal	frac;

	frac.list = NULL;
	frac.list_color = NULL;
	frac.name = argv[1];
	julia_list(&frac, &frac.list);
	if (argc == 2)
	{
		frac.mlx = mlx_init();
		if (!frac.mlx)
		{
			write(1, MINILIBX, ft_strlen(MINILIBX));
			return (1);
		}
		frac.win = mlx_new_window(frac.mlx, WIDTH,
				HEIGHT, frac.name);
		draw_frac(&frac);
		mlx_key_hook(frac.win, key_hook, &frac);
		mlx_loop(frac.mlx);
	}
	write(1, PARAM, ft_strlen(PARAM));
    return (0);
}
