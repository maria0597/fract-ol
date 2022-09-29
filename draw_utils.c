/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:28:19 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/29 17:27:29 by mardolin         ###   ########.fr       */
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
			break;
		if (end->x <= 0 || pixelx < 0 || pixely < 0)
			break;
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

unsigned int	colormagic(int i, double x, double y)
{
	unsigned int	color;
	double			magic;
	double			i2;
	t_c				c;
	magic = sqrt(x * x + y * y);
	i2 = i + 1 - (log(2) / magic) / log(2);
	c.chan[0] = (unsigned char)(sin(0.026 * i2 + 4) * 230 + 25);
	c.chan[1] = (unsigned char)(sin(0.023 * i2 + 2) * 230 + 25);
	c.chan[2] = (unsigned char)(sin(0.01 * i2 + 1) * 230 + 25);
	color = (c.chan[0] << 16) + (c.chan[1] << 8) + (c.chan[2] + 255);
	return (color);
}
