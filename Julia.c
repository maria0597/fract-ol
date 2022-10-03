/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:28:19 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/03 22:50:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 

In complex dynamics, the object of central interest in the dynamical plane is 
the Julia set. For the family Pc, there is an open neighborhood of infinitum in 
the Riemann sphere consisting of points whose orbits tend to infinitum. 
The set of all points whose orbits tend to infinitum is called the basin of 
infinitum.Then the Julia set, deboted by J(Pc) is the boundary of the basin.
Julia set is the chaotic set.

At each c-value on the boundary, Pc has a neutral cycle, a periodic point 
z of period n for which (Pc ^n)'(z) = exp⁡(2πiθ). As c windsonce around the 
boundary of this hyperbolic component θ winds once around the unit circle.
As a consequence, there is a dense set of such c's for which θ is rational. 
In this case, the netural cycle lies in the Julia set but there are still 
region in which all points tend to the neutral cycle. These type of 
periodic points are called parabolic points.

*/
void	julia(t_d *d)
{
	d->y = -1;
	while (++d->y < HEIGHT - 20)
	{
		d->x = -1;
		while (++d->x < WIDTH - 20)
		{
			d->reim.Z_re = 1.5 * (d->x - WIDTH / 2) / \
				(0.5 * d->zoom * WIDTH) + d->movex;
			d->reim.Z_im = (d->y - HEIGHT / 2) / \
				(0.5 * d->zoom * HEIGHT) + d->movey;
			d->n = -1;
			while (++d->n < MAX_ITERATIONS)
			{
				julia_n(reim);
				if ((d->reim.Z_re * d->reim.Z_re + d->reim.Z_im) > 4)
					break ;
			}
			if (d->n < MAX_ITERATIONS)
				my_mlx_pixel_put(d, d->x, d->y, (colormagic((d->n * \
					d->color), d->x, d->y)));
			else
				my_mlx_pixel_put(d, d->x, d->y, 0x000000);
		}
	}
}

int	julia_n(t_d *d)
{
	int	i;

	i = 0;
	while (i < MAX_ITERATIONS
		&& d->reim.Z_re * d->reim.Z_re + d->reim.Z_im * d->reim.Z_im < 4)
	{
		d->reim.Z_re2 = d->reim.Z_re;
		d->reim.Z_im2 = d->reim.Z_im;
		d->reim.newre = d->reim.oldre * d->reim.oldre - \
			d->reim.Z_im2 * d->reim.Z_im2 + d->reim.c_re;
		d->reim.Z_im = 2 * d->reim.Z_re2 * d->reim.Z_im2 + d->reim->c_im;
		i++;
	}
	return (i);
}
