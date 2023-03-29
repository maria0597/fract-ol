/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:28:19 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/06 19:13:21 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

"Take the universe and grind it down to the finest powder and sieve it through 
the finest sieve and then show me one atom of justice, one molecule of mercy. 
And yet," Death waved a hand, "And yet you act as if there is some ideal order 
in the world, as if there is some… some rightness in the universe by which 
it may be judged."

@TheHogfather

*/

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
		if (end->x > WIDTH || pixelx >= WIDTH || pixely >= HEIGHT)
			break ;
		if (end->x <= 0 || pixelx < 0 || pixely < 0)
			break ;
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

	if (d->fractol == 0 || d->fractol == 1)
		return ;
	params = d->params;
	clear(d);
	tree(d, d->point1, params);
	params.b *= -1;
	tree(d, d->point1, params);
	mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
}

void	onlyzoom(t_d *d)
{
	clear(d);
	if (d->fractol == 0)
		mandel_init(d);
	if (d->fractol == 1)
		julia_init(d);
	if (d->fractol == 2)
	{
		d->params.len -= 1 * d->god;
		d->point1.x -= 0.5 * d->god;
		d->point1.y -= 0.5 * d->god;
		retrydraw(d);
	}
	mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
}
