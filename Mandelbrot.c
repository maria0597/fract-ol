/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:13:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/04 22:00:49 by mardolin         ###   ########.fr       */
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

Useful link: http://warp.povusers.org/Mandelbrot/
*/

void	mandelbrot(t_d *d)
{
	int n;
	
	while (d->y < HEIGHT)
	{
		d->reim.c_im = d->reim.MaxImm - d->y * d->reim.Im_factor;
		d->x = 0;
		while (d->x < WIDTH)
		{
			d->reim.c_re = d->reim.MinRe + d->x * d->reim.Re_factor;
			d->reim.Z_re = d->reim.c_re;
			d->reim.Z_im = d->reim.c_im;
			d->isInside = 1;
			n = mandel_n(d);
			if (!d->isInside)
				my_mlx_pixel_put(d, d->x, d->y, (d->color *  n / 100));
		++d->x;
		}
	++d->y;
	}
}

int	mandel_n(t_d *d)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS)
	{
		d->reim.Z_re2 = d->reim.Z_re * d->reim.Z_re;
		d->reim.Z_im2 = d->reim.Z_im * d->reim.Z_im;
		if (d->reim.Z_re2 + d->reim.Z_im2 > 4)
		{
			d->isInside = 0;
			break ;
		}
		d->reim.Z_im = 2 * d->reim.Z_re * d->reim.Z_im + d->reim.c_im;
		d->reim.Z_re = d->reim.Z_re2 - d->reim.Z_im2 + d->reim.c_re;
		i++;
	}
	return (i);
}

// void	zoomin(int x, int y, t_a *exp)
// {
// 	x -= WIDTH / 2;
// 	y -= HEIGHT / 2;
// 	d->x2 = ((d->x - x) - WIDTH) / ((double)HEIGHT * 2);
// 	d->y2 = ((d->y - y) - HEIGHT) / (((double)WIDTH * 2) + y);
// 	d->zoom *= pow(1.001, 70);
// 	d->movex -= d->x2;
// 	d->movey -= d->y2;
// }

void mandel(t_d *d)
{
	d->reim.MinRe = -2.0 * d->zoom - (d->move * d->zoom);
	d->reim.MaxRe = 1.0 * d->zoom - (d->move * d->zoom);
	d->reim.MinIm = -1.2;
	d->reim.MaxImm = d->reim.MinIm + (d->reim.MaxRe - d->reim.MinRe) * HEIGHT / WIDTH ;
}

