/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:29:47 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/18 07:15:12 by mardolin         ###   ########.fr       */
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
		data->params.b += 10;
		retrydraw(data);
		mlx_loop(data->mlx_ptr);
		data->params.b++;
	}
	if (keycode == 123)
	{
		data->params.b -= 10;
		retrydraw(data);
		mlx_loop(data->mlx_ptr);
		data->params.b++;
	}
	return (0);
}
