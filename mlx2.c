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

void mlx_fun(void)
{
    t_d	d;
    
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
}
int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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

int		fract_select(char **argv, t_d *d)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		d->fractol = 0;
		mandelbrot_init(data);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		d->fractol = 1;
		julia_init(data);
	}
	else if (ft_strcmp(argv[1], "tree") == 0)
	{
		d->fractol = 2;
		tree_init(data);
	}
	else
	{
		ft_putendl("Usage: ./fractol [julia] or [mandelbrot] or [tree]");
		return (0);
	}
	return (1);
}