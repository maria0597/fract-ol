/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:55:53 by marvin            #+#    #+#             */
/*   Updated: 2022/09/27 21:55:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int mlx_fun(t_d *d)
{
	d->mlx_ptr = mlx_init();
	if (d->mlx_ptr == NULL)
		return (MLX_ERROR);
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "Welcome to the jungle");
	d->img = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->addr = mlx_get_data_addr(d->img, &d->btx, &d->ll, &d->en);
	if (d->win_ptr == NULL)
	{
		free(d->win_ptr);
		return (MLX_ERROR);
	}
	return (0);
}

void	ft_putchar(char c)
{
	unsigned char	b;

	b = (unsigned char)c;
	write(1, &b, 1);
}

void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	ft_putchar('\n');
}

void		ft_zoom(t_d *d)
{
	float	center_r;
	float	center_i;

	center_r = d->reim.MinRe - d->reim.MaxRe ;
	center_i = d->reim.MaxImm - d->reim.MinIm ;
	d->reim.MaxRe = d->reim.MaxRe + (center_r - d->zoom * center_r) / 2;
	d->reim.MinRe = d->reim.MaxRe + d->zoom * center_r;
	d->reim.MinIm = d->reim.MinIm + (center_i - d->zoom * center_i) / 2;
	d->reim.MaxImm = d->reim.MinIm + d->zoom * center_i;
}

void		ft_move(t_d *d, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = d->reim.MaxRe - d->reim.MinRe;
	center_i = d->reim.MaxImm - d->reim.MinIm;
	if (direction == 'R')
	{
		d->reim.MinRe += center_r * distance ;
		d->reim.MaxRe += center_r * distance;
	}
	else if (direction == 'L')
	{
		d->reim.MaxRe -= center_r * distance;
		d->reim.MinRe -= center_r * distance;
	}
	else if (direction == 'D')
	{
		d->reim.MinIm -= center_i * distance;
		d->reim.MaxImm -= center_i * distance;
	}
	else if (direction == 'U')
	{
		d->reim.MinIm += center_i * distance;
		d->reim.MaxImm  += center_i * distance;
	}
}
