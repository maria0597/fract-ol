/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/09/29 18:53:04 by mardolin         ###   ########.fr       */
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

int	mandel_init(t_d *d, t_complex *reim)
{
	d->n = 0;
	d->x = 0;
	d->y = 0;
	reim->MinRe = -2.0;
	reim->MaxRe = 1.0;
	reim->MinIm = -1.2;
	reim->MaxImm = reim->MinIm + (reim->MaxRe - reim->MinRe) * HEIGHT / WIDTH;
	reim->Re_factor = (reim->MaxRe - reim->MinRe) / (WIDTH - 1);
	reim->Im_factor = (reim->MaxImm - reim->MinIm) / (HEIGHT - 1);
	return (0);
}

void	julia_init(t_d *d, t_complex *reim)
{
	d->color = 0xFFFFFF;
	reim->cre = -0.7;
	reim->cim = 0.27015;
	reim->newre = 0;
	reim->newim = 0;
	reim->oldre = 0;
	reim->oldim = 0;
	d->movex = 0;
	d->movey = 0;
	d->zoom = 1;
}
