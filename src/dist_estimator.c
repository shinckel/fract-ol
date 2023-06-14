/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_estimator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shinckel <shinckel@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 23:49:13 by shinckel          #+#    #+#             */
/*   Updated: 2023/06/13 01:21:09 by shinckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


// function  distance_estimator
//       param(c)  :  complex
//       param(max_iterations)  :  integer
//       param(escape_radius)  :  real        should  be  2.0  or  larger
//       result:  real
//       begin  function
//             declare  z,  z2,  dz  :  complex
//             declare  iterations  :  integer
//             declare  still_iterating  :  boolean
//              
//             let  still_iterating  =  true
//             let  iterations  =  0
//             let  z  =  c
//             let  dz  =  0
//             let  escape_radius  =  2.0     or  larger  value
//              
//             while  (still_iterating)  do
//                   let  z2  =  z2  +  c
//                   let  dz  =  2  *  z  *  dz  +  1
//                   let  z  =  z2
//                   let  iterations  =  iterations  +  1
//                   if  (magnitude(z)  >  escape_radius)  then
//                         let  still_iterating  =  false
//                   else  if  (iterations  >=  max_iterations)  then
//                         let  still_iterating  =  false
//                   end  if
//             end  while
//              
//             let  z  =  magnitude(z)
//             let  dz  =  magnitude(dz)
//             let  result  =  log(z*z)  *  z  /  dz
//       end  function

double	distanceEstimator(t_fractal *fractal)
{
	fractal->iterations = 0;
	fractal->x2 = 0.0;
	fractal->y2 = 0.0;
	 while (fractal->iterations < MAXITER && (fractal->x2 + fractal->y2) < HUGE)
    {
        fractal->tmp = fractal->x2 - fractal->y2 + fractal->cx;
        y = 2 * x * y + fractal->cy;
        x = temp;
        x2 = x * x;
        y2 = y * y;
        iter++;
        xorbit[iter] = x;
        yorbit[iter] = y;
    }
	// it return the distance estimative
}