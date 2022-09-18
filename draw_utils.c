/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:28:19 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/18 07:17:23 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->btx / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_data *data, t_i_pnt *begin, t_i_pnt *end)
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
		my_mlx_pixel_put(data, pixelx, pixely, data->color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, 0, 0);
}

void	retrydraw(t_data *data)
{
	t_itr_prms	params;

	params = data->params;
	mlx_destroy_image(data->mlx_ptr, data->img);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &(data->btx), &(data->ll), &(data->en));
	tree(data, data->point1, params);
	params.b *= -1;
	tree(data, data->point1, params);
	mlx_put_image_to_window(data->mlx_ptr, data-> win_ptr, data->img, 0, 0);
}

int	main_loop(t_data *data)
{
	if (data->rt == 1)
	{
		retrydraw(data);
		data->rt = 0;
	}
	return (0);
}
