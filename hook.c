/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:29:47 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/04 23:36:58 by mardolin         ###   ########.fr       */
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
		// d->params.b += 1;
		d->movex += 20;
		d->movey += 20;
		clear(d);
		mandel_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
		// retrydraw(d);
		// mlx_loop(d->mlx_ptr);
		d->params.b++;
	}
	if (keycode == 126)
	{
		// d->params.b -= 1;
		d->movex -= 20;
		d->movey -= 20;
		clear(d);
		mandel_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
		// retrydraw(d);
		// mlx_loop(d->mlx_ptr);
		d->params.b++;
	}
	if (keycode == 78)
	{
		d->zoom += 0.01;
		clear(d);
		mandel(d);
		mandel_init(d);
		// julia_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
	if (keycode == 69)
	{
		d->zoom -= 0.01;
		// d->movex *= 0.1;
		// d->movey *= 0.1;
		clear(d);
		mandel(d);
		mandel_init(d);
		// julia_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
	if (keycode == 123)
	{
		d->move += 0.1;
		clear(d);
		mandel(d);
		mandel_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
	if (keycode == 124)
	{
		d->move -= 0.1;
		// d->movex -= 0.1;
		// d->movey -= 0.1;
		clear(d);
		// julia_init(d);
		mandel(d);
		mandel_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_d *d)
{
	// x -= WIDTH / 2;
	// y -= HEIGHT / 2;
	// zoom(d, 0.1)
	
	if (button == 5)
	{
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
		clear(d);
		// julia_init(d);
		mandel_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	}
		// d->params.len += 1;
		// d->point1.x += 0.5;
		// d->point1.y += 0.5;
		// retrydraw(d);
		// d->zoom += 0.01;
	// 	clear(d);
	// 	julia_init(d);
	// 	// mandel_init(d);
	// 	mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
	// 	mlx_loop(d->mlx_ptr);
	// }
	else if (button == 4)
	{
		d->zoom += 0.1;
		ft_zoom(d);
		// d->params.len -= 1;
		// d->point1.x -= 0.5;
		// d->point1.y -= 0.5;
		// retrydraw(d);
		// d->zoom -= 0.05;
		clear(d);
		// julia_init  (d);
		mandel_init(d);
		mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
		// mlx_loop(d->mlx_ptr);
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

// void configure_hook(t_d *d)
// {
// 	mlx_key_hook(d->win_ptr, key_hook, &d);
// 	mlx_mouse_hook(d->win_ptr, mouse_hook, &d);
// 	mlx_loop_hook(d->mlx_ptr, main_loop, &d);
// 	mlx_hook(d->win_ptr, 17, 0, close_window, &d);
// 	mlx_loop(d->mlx_ptr);
// }