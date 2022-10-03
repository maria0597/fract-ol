/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/03 14:36:08 by mardolin         ###   ########.fr       */
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
	d->x = 0;
	d->y = 0;
	return (0);
}

int	mandel_init(t_d *d)
{
	d->n = 0;
	d->x = 0;
	d->y = 0;
	d->color = 0xFFFFFF;
	d->reim.MinRe = -2.0 * d->zoom;
	d->reim.MaxRe = 1.0 * d->zoom;
	d->reim.MinIm = -1.2 * d->zoom;
	d->reim.MaxImm = d->reim.MinIm + (d->reim.MaxRe - d->reim.MinRe) * HEIGHT / WIDTH;
	d->reim.Re_factor = (d->reim.MaxRe - d->reim.MinRe) / (WIDTH - 1);
	d->reim.Im_factor = (d->reim.MaxImm - d->reim.MinIm) / (HEIGHT - 1);
	mandelbrot(d);
	return (0);
}

void	julia_init(t_d *d, t_complex *reim)
{
	d->color = 0x00FF00;
	reim->cre = -0.7;
	reim->cim = 0.27015;
	reim->newre = 0;
	reim->newim = 0;
	reim->oldre = 0;
	reim->oldim = 0;
	d->movex = 0;
	d->movey = 0;
	// d->zoom = 1;
}

// void	init_fractal(t_d *d, t_complex *reim)
// {
// 	if (d->fractal == 1)
// 		mandel_init(&d, &reim);
// 	if (d->fractal == 2)
// 		julia_init(&d, &reim);
// 	if (d->fractal == 3)
// 		treeinit(&d);
// }

// void	whichfractol(t_d *d, t_complex *reim)
// {
// 	if (d->fractal == 1)
// 		julia(&d, &reim);
// 	if (d->fractal == 2)
// 		mandelbrot(&d, &reim);
// 	if (d->fractal == 3)
// 	{
// 		tree(&d, d->point1, d->params);
// 		d->params.b *= -1;
// 		tree(&d, d->point1, d->params);
// 	}
// }
