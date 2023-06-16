/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:00:19 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/15 14:00:38 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int deal_keys(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(1);
	}
	return (0);
}
