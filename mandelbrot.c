/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 03:13:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/21 08:21:47 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	square_complex(double *re, double *im)
{
	double	tmp;
    
	tmp = *re;
	*re = (*re) * (*re) - (*im) * (*im);
	*im = 2.0 * (*im) * tmp;
}

void	mandelbr(t_d *d)
{
    for (int row = 0; row < HEIGHT; row++) 
    {
        for (int col = 0; col < WIDTH; col++) 
        {
            double c_re = (col - WIDTH / 2) * 4 / WIDTH;
            double c_im = (row - HEIGHT / 2) * 4 / WIDTH;
            int iteration = 0;
            while (d->x * d->x + d->y * d->y <= 4 && iteration < MAX_ITERATIONS) 
            {
                double x_new = d->x * d->x - d->y * d->y + c_re;
                d->y = 2 * d->x * d->y + c_im;
                d->x = x_new;
                iteration++;
            }
            if (iteration < MAX_ITERATIONS) 
                my_mlx_pixel_put(d, col, row, 0xFFFFFF);
            else 
                my_mlx_pixel_put(d, col, row, 0x0000FF);
        }
    }
    mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}

int mandel_init(t_d *d)
{
    d->x = 0;
	d->y = 0;
	return (0);
}