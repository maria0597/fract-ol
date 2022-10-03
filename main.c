/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:01:00 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/03 14:36:15 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
/*

Big whorls have little whorls,
Wich feed on their velocity;
And little whorls have lesser whorls,
And so on to viscosity
(in the mulecolar sense).

@Richardson

*/
// int	main(int argc, char **argv)
int main(void)
{
	t_d			d;
	// t_complex	reim;
	
	// d.zoom = 1;
	// julia_init(&d, &reim);
	// treeinit(&d);
	// init_fractal(&d,&reim);
	// mandel_init(&d);
	d.mlx_ptr = mlx_init();
	if (d.mlx_ptr == NULL)
		return (MLX_ERROR);
	d.win_ptr = mlx_new_window(d.mlx_ptr, WIDTH, HEIGHT, TITLE);
	d.img = mlx_new_image(d.mlx_ptr, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.btx, &d.ll, &d.en);
	if (d.win_ptr == NULL)
	{
		free(d.win_ptr);
		return (MLX_ERROR);
	}
	d.zoom = 1;
	mandel_init(&d);
	// tree(&d, d.point1, d.params);
	// d.params.b *= -1;
	// tree(&d, d.point1, d.params);
	// mandelbrot(&d, &reim);
	// julia(&d, &reim);
	// whichfractol(&d, &reim);
	mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img, 0, 0);
	mlx_key_hook(d.win_ptr, key_hook, &d);
	mlx_mouse_hook(d.win_ptr, mouse_hook, &d);
	mlx_loop_hook(d.mlx_ptr, main_loop, &d);
	mlx_hook(d.win_ptr, 17, 0, close_window, &d);
	mlx_loop(d.mlx_ptr);
	free(d.mlx_ptr);
}
