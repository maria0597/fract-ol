/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/06 15:55:45 by mardolin         ###   ########.fr       */
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
		d->reim.c_re = -0.835;
		d->reim.c_im = -0.2321;
		return ;
	}
	d->reim.c_re = ft_atof(argv[2]);
	d->reim.c_im = ft_atof(argv[3]);
	if (!ft_strchr(argv[2], '.'))
		error_exit(d);
	if (!ft_strchr(argv[3], '.'))
		error_exit(d);
	if (d->reim.c_re > 2.0 || d->reim.c_re < -2.0)
		error_exit(d);
	if (d->reim.c_im >= 2.0 || d->reim.c_im <= -2.0)
		error_exit(d);
}

float	ft_atof(char *str)
{
	int		i;
	float	nb;
	int		neg;
	float	div;

	nb = 0;
	div = 0.1;
	neg = 1;
	i = skip(str, &neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - '0') * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * neg);
}
