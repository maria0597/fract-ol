/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mardolin <mardolin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:28:31 by mardolin          #+#    #+#             */
/*   Updated: 2022/10/04 23:37:17 by mardolin         ###   ########.fr       */
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
	// d->reim.MinRe = -2.0 * d->zoom - (d->move * d->zoom);
	// d->reim.MaxRe = 1.0 * d->zoom - (d->move * d->zoom);
	// d->reim.MinIm = -1.2;
	// d->reim.MaxImm = d->reim.MinIm + (d->reim.MaxRe - d->reim.MinRe) * HEIGHT / WIDTH ;
	d->reim.Re_factor = (d->reim.MaxRe - d->reim.MinRe) / (WIDTH - 1);
	d->reim.Im_factor = (d->reim.MaxImm - d->reim.MinIm) / (HEIGHT - 1);
	mandelbrot(d);
	return (0);
}

int	julia_init(t_d *d)
{
	d->color = 0x0000FF;
	// d->reim.c_re = -0.70176;
	// d->reim.c_im = - 0.3842;
	d->reim.Z_re = 0;
	d->reim.Z_im = 0;
	d->reim.Z_re2 = 0;
	d->reim.Z_im2 = 0;
	d->movex = 0;
	d->movey = 0;
	julia(d);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0' && s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		fract_select(char **argv, t_d *d)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
	{
		d->fractol = 0;
		mandel_init(d);
	}
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		d->fractol = 1;
		julia_init(d);
	}
	else if (ft_strcmp(argv[1], "tree") == 0)
	{
		d->fractol = 2;
		treeinit(d);
	}
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (c);
	return (0);
}

int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

double	ft_atof(char *str)
{
	int		i;
	double	nb;
	int		is_neg;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
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
	return (nb * is_neg);
}

void	get_julia_starting_values(t_d *d, int argc, char **argv)
{
	if (d->fractol != 1 || argc == 2)
	{
		d->reim.c_re = 0.285;
		d->reim.c_im = 0.01;
		return ;
	}
	// if (argc == 3 || !ft_strchr(argv[2], '.') || !ft_strchr(argv[3], '.'))
	// {
	// 	ft_putendl("Error");
	// 	close_window(d);
	// }
	// if (!ft_strchr(argv[2], '.'))
	// 	ft_putendl("Error");
	// if (!ft_strchr(argv[3], '.'))
	// 	ft_putendl("Error");
	d->reim.c_re = ft_atof(argv[2]);
	d->reim.c_im = ft_atof(argv[3]);
	if (d->reim.c_re > 2.0 || d->reim.c_re < -2.0)
		ft_putendl("Error");
	if (d->reim.c_im >= 2.0 || d->reim.c_im <= -2.0)
		ft_putendl("Error");
}

void	handle_args(t_d *d, int argc, char **argv)
{
	fract_select(argv, d);
	if (d->fractol != 1 && argc > 3)
		ft_putendl("Error");
	else if (d->fractol == 1 && argc > 5)
		ft_putendl("Error");
	get_julia_starting_values(d, argc, argv);
}