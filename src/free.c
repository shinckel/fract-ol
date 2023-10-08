/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:22:14 by shinckel          #+#    #+#             */
/*   Updated: 2023/10/08 14:32:05 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// I used to store data in lists...
// void	freeRef(t_list **headRef)
// {
// 	t_list	*current;
// 	t_list	*next;

// 	current = *headRef;
// 	printf("what is this: %p\n", *headRef);
// 	if (current == NULL)
// 		return ;
// 	while (current != NULL)
// 	{
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// 	*headRef = NULL;
// }

int	freeall(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->c);
	free(fractal->mlx);
	exit(0);
}

int	close_game(t_fractal *fractal)
{
	write(1, FINISH, strlen(FINISH));
	freeall(fractal);
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(EXIT_SUCCESS);
}
