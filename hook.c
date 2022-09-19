/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:29:47 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/19 18:25:44 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(EXIT_SUCCESS);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 124)
	{
		data->params.b += 1;
		retrydraw(data);
		mlx_loop(data->mlx_ptr);
		data->params.b++;
	}
	if (keycode == 123)
	{
		data->params.b -= 1;
		retrydraw(data);
		mlx_loop(data->mlx_ptr);
		data->params.b++;
	}
	if (keycode == 125)
	{
		data->params.len -= 1;
		retrydraw(data);
		mlx_loop(data->mlx_ptr);
		data->params.len++;
	}
	else if (keycode == 126)
	{
		data->params.len += 1;
		retrydraw(data);
		mlx_loop(data->mlx_ptr);
		data->params.len++;
	}
	return (0);
}

int	mouse_hook(int button, t_f_pnt *start, t_data *data)
{
	printf("%i\n", button);
	if (button == 1)
	{
		start->x += 1;
		start->y += 1;
		retrydraw(data);
		//mlx_loop(start->mlx_ptr);
		start->x++;
	}
	// else if (button == 2)
	// {
	// 	data->params.len -= 1;
	// 	retrydraw(data);
	// 	mlx_loop(data->mlx_ptr);
	// 	data->params.len++;
	// }
	// if (button == 1 || button == 2 || button == 4 || button == 5)
	// {
	// 	retrydraw(data);
	// 	mlx_loop(data->mlx_ptr);
	// }
	return (0);
}