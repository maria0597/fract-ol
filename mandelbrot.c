/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:13:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/27 22:14:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*

The Mandelbrot set M is one of the most interesting and beautiful objects in all
mathematics. Amazingly, it arises as the parameter plane for the seeminghly 
simple quadratic family P(z) = z^2 + c. When you will run this code, you will see
a picture that describes the fate of the orbit of the only critical point for 
family, namely 0. If the orbit of 0 does not tend to infinitum, then the 
corresponding parameter c lies in M and we color this point black. If the orbit
does escape to infinitum, then c is not in the M and we color it according to how
quickly the orbit of 0 reaches the exterior of a large disk surronding the origin.

The large black open regions visible in the Mandelbrot set are regions for which Pc 
has an attracting cycle of some given period. If Pc has an attracting cycle, 
then the orbit of the critical point must tend to this cycle. Hence there can be at 
most one attractive cycle for a quadratic polynomial.

If we zoom in to any portion of the boundary of the M, it turns out that this zoom 
is very different from any other zoom that is non-symmetric with respect to c → sum(c).

*/
void	mandelbr(t_d *d, t_f_pnt start, t_itr_prms params)
{
	
}
