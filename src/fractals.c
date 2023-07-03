/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:33:54 by shinckel          #+#    #+#             */
/*   Updated: 2023/07/03 18:07:57 by shinckel         ###   ########.fr       */
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

t_color mandelbrot(t_fractal *frac, int x, int y)
{
	double	smooth;
	t_color	color_effect;

	frac->flag = 1;
	frac->cx = x * ((0.47 + 2.0) / WIDTH) - 2.0;
	frac->cy = y * ((1.12 + 1.12) / HEIGHT) - 1.12;
	smooth = smooth_coloring(frac, 0, 0);
	color_effect = get_color(smooth, frac->flag);
	return (color_effect);
}

t_color julia(t_fractal *frac, int x, int y)
{
	double	smooth;
	double	xaxis;
	double	yaxis;
	t_color	color_effect;

	frac->flag = 2;
	xaxis = 3 * (x - WIDTH / 2.0) / WIDTH;
    yaxis = 3 * (y - HEIGHT / 2.0) / HEIGHT;
	//set1
	// frac->cx = -0.7;
	// frac->cy = 0.27015;
	//set 2
	// frac->cx = -0.8;
	// frac->cy = 0.156;
	//set 3
	// frac->cx = 0.0;
	// frac->cy = 0.8;
	//set 4
	frac->cx = 0.285;
	frac->cy = 0.01;
	//set 5
	// frac->cx = - 0.74543;
	// frac->cy = 0.11301;
	//set 6
	// frac->cx = 0.355;
	// frac->cy = 0.355;
	smooth = smooth_coloring(frac, xaxis, yaxis);
	color_effect = get_color(smooth, frac->flag);
	return (color_effect);
}
