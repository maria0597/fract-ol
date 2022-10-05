/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:29:47 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/05 16:25:25 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_d *d)
{
	mlx_destroy_window(d->mlx_ptr, d->win_ptr);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_d *d)
{
	if (keycode == 53)
		close_window(d);
	if (keycode == 125)
	{
		d->params.b += 1;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
	}
	if (keycode == 126)
	{
		d->params.b -= 1;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
	}
	if (keycode == 123)
	{
		d->move += 0.1;
		whichfractol(d);
	}
	if (keycode == 124)
	{
		d->move -= 0.1;
		whichfractol(d);
	}
	zoom_hook(keycode, d);
	return (0);
}

int zoom_hook(int keycode, t_d *d)
{
	if (keycode == 78)
	{
		d->zoom += 0.01;
		whichfractol(d);
	}
	if (keycode == 69)
	{
		d->zoom -= 0.01;
		whichfractol(d);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_d *d)
{
	if (button == 5)
	{
		d->god = 1;
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		d->zoom -= 0.05;
		ft_zoom(d);
		if (x < 0)
			ft_move(d, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			ft_move(d, (double)x / WIDTH, 'R');
		if (y < 0)
			ft_move(d, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			ft_move (d, (double)y / HEIGHT, 'D');
		whichfractol(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
	if (button == 4)
	{
		d->god = -1;
		d->zoom += 0.1;
		ft_zoom(d);
		whichfractol(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
	return (0);
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
