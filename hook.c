/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:29:47 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/19 22:26:03 by mardolin         ###   ########.fr       */
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
	printf("%d %d\n", x, y);
	if (button == 4)
	{
		d->params.len += 1;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
		d->params.len++;
	}
	else if (button == 5)
	{
		d->params.len -= 1;
		retrydraw(d);
		mlx_loop(d->mlx_ptr);
		d->params.len++;
	}
	return (0);
}
