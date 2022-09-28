/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:01:00 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/28 11:00:24 by mardolin         ###   ########.fr       */
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
	t_d	d;

	treeinit(&d);
	// mandel_init(&d);
	d.mlx_ptr = mlx_init();
	if (d.mlx_ptr == NULL)
		return (MLX_ERROR);
	d.win_ptr = mlx_new_window(d.mlx_ptr, WIDTH, HEIGHT, "Welcome to the jungle");
	d.img = mlx_new_image(d.mlx_ptr, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.btx, &d.ll, &d.en);
	if (d.win_ptr == NULL)
	{
		free(d.win_ptr);
		return (MLX_ERROR);
	}
	// mlx_fun();
	tree(&d, d.point1, d.params);
	d.params.b *= -1;
	tree(&d, d.point1, d.params);
	//mandelbr(&d);
	mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img, 0, 0);
	mlx_key_hook(d.win_ptr, key_hook, &d);
	mlx_mouse_hook(d.win_ptr, mouse_hook, &d);
	mlx_loop_hook(d.mlx_ptr, main_loop, &d);
	mlx_hook(d.win_ptr, 17, 0, close_window, &d);
	// configure_hook(&d);
	mlx_loop(d.mlx_ptr);
	free(d.mlx_ptr);
}
