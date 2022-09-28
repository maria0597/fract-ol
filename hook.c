/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:29:47 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/21 03:05:29 by mardolin         ###   ########.fr       */
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
	if (keycode == 124)
	{
		d->params.b += 1;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
		d->params.b++;
	}
	if (keycode == 123)
	{
		d->params.b -= 1;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
		d->params.b++;
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_d *d)
{

	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	printf("%d %d\n", x, y);
	if (button == 4)
	{
		d->params.len += 1;
		d->point1.x += 0.5;
		d->point1.y += 0.5;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
	}
	else if (button == 5)
	{
		d->params.len -= 1;
		d->point1.x -= 0.5;
		d->point1.y -= 0.5;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
	}
	return (0);
}

void configure_hook(t_d *d)
{
	mlx_key_hook(d->win_ptr, key_hook, &d);
	mlx_mouse_hook(d->win_ptr, mouse_hook, &d);
	mlx_loop_hook(d->mlx_ptr, main_loop, &d);
	mlx_hook(d->win_ptr, 17, 0, close_window, &d);
}