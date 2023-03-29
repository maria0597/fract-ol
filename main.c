/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:01:00 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/06 15:52:47 by mardolin         ###   ########.fr       */
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

int	fract_select(int argc, char **argv, t_d *d)
{
	(void)argc;
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		d->fractol = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		d->fractol = 1;
	else if (ft_strcmp(argv[1], "tree") == 0)
	{
		d->fractol = 2;
		treeinit(d);
	}
	return (1);
}

void	whichfractol(t_d *d)
{
	clear(d);
	if (d->fractol == 0)
	{
		mandel(d);
		mandel_init(d);
	}
	if (d->fractol == 1)
		julia_init(d);
	if (d->fractol == 2)
	{
		d->params.len -= 1 * d->god;
		d->point1.x -= 0.5 * d->god;
		d->point1.y -= 0.5 * d->god;
		retrydraw(d);
	}
	mlx_put_image_to_window(d->mlx_ptr, d-> win_ptr, d->img, 0, 0);
}

void	handle_args(t_d *d, int argc, char **argv)
{
	fract_select(argc, argv, d);
	if (d->fractol != 1 && argc > 3)
		ft_putendl("Error");
	else if (d->fractol == 1 && argc > 5)
		ft_putendl("Error");
	if (d->fractol == 1)
		get_julia_starting_values(d, argc, argv);
}

void	error_exit(t_d *d)
{
	ft_putendl("Error");
	close_window(d);
}

int	main(int argc, char **argv)
{
	t_d	d;

	mlx_fun(&d);
	d.zoom = 1;
	d.move = 0;
	mandel(&d);
	if (argc < 2)
	{
		ft_putendl("Usage: ./fractol [julia] or [mandelbrot] or [tree]");
		close_window(&d);
	}
	if (argc == 3)
		error_exit(&d);
	if (argc >= 2)
	{
		handle_args(&d, argc, argv);
		whichfractol(&d);
	}
	mlx_put_image_to_window(d.mlx_ptr, d.win_ptr, d.img, 0, 0);
	mlx_key_hook(d.win_ptr, key_hook, &d);
	mlx_mouse_hook(d.win_ptr, mouse_hook, &d);
	mlx_loop_hook(d.mlx_ptr, main_loop, &d);
	mlx_hook(d.win_ptr, 17, 0, close_window, &d);
	mlx_loop(d.mlx_ptr);
	free(d.mlx_ptr);
}
