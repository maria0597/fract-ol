/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:28:19 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/19 22:31:19 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_d *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->ll + x * (d->btx / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_d *d, t_i_pnt *begin, t_i_pnt *end)
{
	float	deltax;
	float	deltay;
	int		pixels;
	float	pixelx;
	float	pixely;

	deltax = end->x - begin->x;
	deltay = end->y - begin->y;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	pixely = begin->y;
	pixelx = begin->x;
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(d, pixelx, pixely, d->color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img, 0, 0);
}

void	clear(t_d *d)
{
	mlx_destroy_image(d->mlx_ptr, d->img);
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	d->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &(d->btx), &(d->ll), &(d->en));
}

void	retrydraw(t_d *d)
{
	t_itr_prms	params;

	params = d->params;
	clear(d);
	tree(d, d->point1, params);
	params.b *= -1;
	tree(d, d->point1, params);
	mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
}

int	main_loop(t_d *d)
{
	if (d->rt == 1)
	{
		retrydraw(d);
		d->rt = 0;
	}
	return (0);
}
