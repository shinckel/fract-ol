/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/30 20:21:07 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	deal_keys(int keycode, fractal *fractal)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(1);
	}
	return (0);
}

// int deal_keys(int keycode, void *param) {
//     // Handle key events here
//     return (0);
// }