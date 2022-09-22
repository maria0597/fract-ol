/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackronos <blackronos@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:13:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/22 14:04:09 by blackronos       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The Mandelbrot set M is one of the most interesting and beautiful objects in all
mathematics. Amazingly, it arises as the parameter plane for the seeminghly 
simple quadratic family P(z) = z^2 + c. When you will run this code, you will see
a picture that describes the fate of the orbit of the only critical point for 
family, namely 0. If the orbit of 0 does not tend to infinitum, then the 
corresponding parameter c lies in M and we color this point black. If the orbit
does escape to infinitum, then c is not in the M and we color it according to how
quickly the orbit of 0 reaches the exterior of a large disk surronding the origin.
*/

#include "fractol.h"

void	mandelbr(t_d *d, t_f_pnt start, t_itr_prms params)
{
	t_f_pnt reim;

	reim.x =  start.c_re;
	reim.y =  start.c_im;
	while (params.row < HEIGHT) 
	{
		while (params.col < WIDTH) 
		{
			reim.c_re = (params.col - WIDTH / 2) * 4 / WIDTH;
			reim.c_im = (params.row - HEIGHT / 2) * 4 / WIDTH;
			int iteration = 0;
			while (d->x * d->x + d->y * d->y <= 4 && iteration < MAX_ITERATIONS) 
			{
				double x_new = d->x * d->x - d->y * d->y + reim.c_re;
				d->y = 2 * d->x * d->y + reim.c_im;
				d->x = x_new;
				iteration++;
			}
			if (iteration < MAX_ITERATIONS) 
				my_mlx_pixel_put(d, params.col, params.row, 0xFFFFFF);
			else 
				my_mlx_pixel_put(d, params.col, params.row, 0x0000FF);
		}
		params.col++;
	}
	params.row++;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}

int mandel_init(t_d *d)
{
	d->x = 0;
	d->y = 0;
	d->params.row = 0;
	d->params.col = 0;
	return (0);
}