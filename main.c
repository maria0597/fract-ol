/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:01:00 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/18 07:38:56 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

Big whorls have little whorls,
Wich feed on their velocity;
And little whorls have lesser whorls,
And so on to viscosity
(in the mulecolar sense).

@Richardson
*/

#include "fractol.h"

int	main(void)
{
	t_data	data;

	treeinit(&data);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
								"tree");
	data.img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.btx, &data.ll, &data.en);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	tree(&data, data.point1, data.params);
	data.params.b *= -1;
	tree(&data, data.point1, data.params);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img, 0, 0);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop_hook(data.mlx_ptr, main_loop, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	free(data.mlx_ptr);
}
