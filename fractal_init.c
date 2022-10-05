/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/05 17:43:48 by mardolin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	treeinit(t_d *d)
{
	d->point1.x = WIDTH / 2;
	d->point1.y = HEIGHT - 40;
	d->color = 0x00FFFF;
	d->params.len = 115;
	d->params.a = 90;
	d->params.b = 30;
	 d->god = 1;
	d->x = 0;
	d->y = 0;
	tree(d, d->point1, d->params);
	d->params.b *= -1;
	tree(d, d->point1, d->params);
	return (0);
}

int	mandel_init(t_d *d)
{
	d->n = 0;
	d->x = 0;
	d->y = 0;
	d->movex = 0;
	d->movey = 0;
	d->color = 0x0000FF;
	d->reim.Re_factor = (d->reim.MaxRe - d->reim.MinRe) / (WIDTH - 1);
	d->reim.Im_factor = (d->reim.MaxImm - d->reim.MinIm) / (HEIGHT - 1);
	mandelbrot(d);
	return (0);
}

int	julia_init(t_d *d)
{
	d->color = 0x0001FF;
	d->reim.Z_re = 0;
	d->reim.Z_im = 0;
	d->reim.Z_re2 = 0;
	d->reim.Z_im2 = 0;
	d->movex = 0;
	d->movey = 0;
	julia(d);
	return (0);
}

void	get_julia_starting_values(t_d *d, int argc, char **argv)
{
	if (d->fractol == 1 && argc == 2)
	{
		d->reim.c_re = 0;
		d->reim.c_im = -0.8;
		return ;
	}
	d->reim.c_re = ft_atof(argv[2]);
	d->reim.c_im = ft_atof(argv[3]);
	if (d->reim.c_re > 2.0 || d->reim.c_re < -2.0)
		ft_putendl("Error");
	if (d->reim.c_im >= 2.0 || d->reim.c_im <= -2.0)
		ft_putendl("Error");
}

int		fract_select(int argc, char **argv, t_d *d)
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
		mandel_init(d);
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