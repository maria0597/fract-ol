/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:13:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/29 20:43:15 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*

The Mandelbrot set M is one of the most interesting and beautiful objects in 
all mathematics. Amazingly, it arises as the parameter plane for the seeminghly
simple quadratic family P(z) = z^2 + c. When you will run this code, you will 
see a picture that describes the fate of the orbit of the only critical point 
for family, namely 0. If the orbit of 0 does not tend to infinitum, then the 
corresponding parameter c lies in M and we color this point black. If the orbit
does escape to infinitum, then c is not in the M and we color it according to 
how quickly the orbit of 0 reaches the exterior of a large disk surronding 
the origin.

The large black open regions visible in the Mandelbrot set are regions for which 
Pc has an attracting cycle of some given period. If Pc has an attracting cycle, 
then the orbit of the critical point must tend to this cycle. Hence there can be 
at most one attractive cycle for a quadratic polynomial.

If we zoom in to any portion of the boundary of the M, it turns out that this 
zoom is very different from any other zoom that is non-symmetric with respect
to c → sum(c).

*/
void	mandelbrot(t_d *d, t_complex *reim)
{
	while (d->y < HEIGHT)
	{
		reim->c_im = reim->MaxImm - d->y * reim->Im_factor;
		d->x = 0;
		while (d->x < WIDTH)
		{
			reim->c_re = reim->MinRe + d->x * reim->Re_factor;
			reim->Z_re = reim->c_re;
			reim->Z_im = reim->c_im;
			d->isInside = 1;
			mandel_n(d, reim);
			if (d->isInside)
				my_mlx_pixel_put(d, d->x, d->y, 0xFFFFFF);
		++d->x;
		}
	++d->y;
	}
}

int	mandel_n(t_d *d, t_complex *reim)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		reim->Z_re2 = reim->Z_re * reim->Z_re;
		reim->Z_im2 = reim->Z_im * reim->Z_im;
		if (reim->Z_re2 + reim->Z_im2 > 4)
		{
			d->isInside = 0;
			break ;
		}
		reim->Z_im = 2 * reim->Z_re * reim->Z_im + reim->c_im;
		reim->Z_re = reim->Z_re2 - reim->Z_im2 + reim->c_re;
		i++;
	}
	return (i);
}
